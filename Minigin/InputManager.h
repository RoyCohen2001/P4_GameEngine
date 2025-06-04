#pragma once
#include <map>
#include "Singleton.h"
#include "Gamepad.h"
#include "Command.h"

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager(const InputManager& other) = delete;
		InputManager(InputManager&& other) = delete;
		InputManager& operator=(const InputManager& other) = delete;
		InputManager& operator=(InputManager&& other) = delete;

		

		bool ProcessInput();

		void BindCommandToGamepad(Button button, Command* command);
		void BindCommandToKeyboard(unsigned int key, Command* command);

	private:
		friend class Singleton<InputManager>;

		InputManager();
		~InputManager() = default;

		bool ProcessKeyboardInput();
		void ProcessControllerInput();
		
		bool IsDownThisFrame(unsigned int button) const;
		bool IsUpThisFrame(unsigned int button) const;
		bool IsPressed(unsigned int button) const;

		std::unique_ptr<Gamepad> m_pGamepad;
		std::map<Button, Command*> m_GamepadCommands;
		std::map<unsigned int, Command*> m_KeyboardCommands;

		unsigned int buttonsPressedThisFrame{};
		unsigned int buttonsReleasedThisFrame{};
	};
}
