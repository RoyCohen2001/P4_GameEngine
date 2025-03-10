#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <XInput.h>
#include "Command.h"

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsDownThisFrame(unsigned int button) const;
		bool IsUpThisFrame(unsigned int button) const;
		bool IsPressed(unsigned int button) const;

		//void BindDefaultControllerCommands(GameActor& actor);
		//void BindDefaultKeyboardCommands(GameActor& actor);

	private:
		XINPUT_STATE currentState{};
		XINPUT_STATE previousState{};
		unsigned int m_controllerIndex{ 0 };
	
		unsigned int buttonsPressedThisFrame{};
		unsigned int buttonsReleasedThisFrame{};


		// Controller buttons
		Command* DpadUp_;
		Command* DpadDown_;
		Command* DpadLeft_;
		Command* DpadRight_;

		// Keyboard buttons
		Command* KeyW_;
	};
}
