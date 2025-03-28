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

	private:
		XINPUT_STATE currentState{};
		XINPUT_STATE previousState{};
		unsigned int m_controllerIndex{ 0 };
	
		unsigned int buttonsPressedThisFrame{};
		unsigned int buttonsReleasedThisFrame{};
	};
}
