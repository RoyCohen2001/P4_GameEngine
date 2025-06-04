#include <SDL.h>
#include "InputManager.h"

#include <iostream>


namespace dae {

	bool InputManager::ProcessInput()
	{
		ProcessControllerInput();
		
		if (!ProcessKeyboardInput()) {
			return false;
		}
		return true;
	}

	InputManager::InputManager():
		m_pGamepad(std::make_unique<Gamepad>(0))
	{
	}

	void InputManager::BindCommandToGamepad(Button button, Command* command)
	{
		m_GamepadCommands[button] = command;
	}
	
	void InputManager::BindCommandToKeyboard(unsigned int key, Command* command)
	{
		m_KeyboardCommands[key] = command;
	}
	
	bool InputManager::ProcessKeyboardInput()
	{
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				return false;
			}
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_ESCAPE) {
					return false;
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {;
			}

			for (const auto& [key, command] : m_KeyboardCommands)
			{
				if (SDL_GetKeyboardState(nullptr)[key] && command)
				{
					command->Execute();
				}
			}
		}

		return true;
	}

	void InputManager::ProcessControllerInput()
	{
		m_pGamepad->Update();
		
		for (const auto& [button, command]: m_GamepadCommands)
		{
			if (m_pGamepad->IsPressed(button) && command)
			{
				command->Execute();
			}
		}
	}

	bool dae::InputManager::IsDownThisFrame(unsigned int button) const
	{
		return m_pGamepad->IsDownThisFrame(static_cast<Button>(button));
	}
	
	bool dae::InputManager::IsUpThisFrame(unsigned int button) const
	{
		return m_pGamepad->IsUpThisFrame(static_cast<Button>(button));
	}
	
	bool dae::InputManager::IsPressed(unsigned int button) const
	{
		return m_pGamepad->IsPressed(static_cast<Button>(button));
	}
	
}

