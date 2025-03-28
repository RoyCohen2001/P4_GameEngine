#include <SDL.h>
#include "InputManager.h"
//#include "WinBase.h"

bool dae::InputManager::ProcessInput()
{
	// 1. Poll the controller
	//CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
	//ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	//
	//XInputGetState(m_controllerIndex, &currentState);
	//
	//auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
	//buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
	//buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);

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
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...
	}

	return true;
}

bool dae::InputManager::IsDownThisFrame(unsigned int button) const
{
	return buttonsPressedThisFrame & button;
}
bool dae::InputManager::IsUpThisFrame(unsigned int button) const
{
	return buttonsReleasedThisFrame & button;
}
bool dae::InputManager::IsPressed(unsigned int button) const
{
	return currentState.Gamepad.wButtons & button;
}

