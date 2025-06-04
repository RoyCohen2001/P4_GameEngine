#include "Gamepad.h"
#include <XInput.h>

namespace dae {
    class Gamepad::Impl {
    public:
        Impl(int idx) :
    	m_ControllerIndex(idx)
        {
	        ZeroMemory(&m_State, sizeof(m_State));
        }
    
        void Update()
        {
	        XInputGetState(m_ControllerIndex, &m_State);
        }
    
		bool IsPressed(Button button) const
		{
			return m_State.Gamepad.wButtons & static_cast<WORD>(button);
		}
    
		bool IsDownThisFrame(Button button) const
		{
			return (m_State.Gamepad.wButtons & static_cast<WORD>(button)) && !IsPressed(button);
		}
    
        bool IsUpThisFrame(Button button) const
    	{
			return !(m_State.Gamepad.wButtons & static_cast<WORD>(button)) && IsPressed(button);
        }
    private:
        int m_ControllerIndex;
        XINPUT_STATE m_State{};
    };
    
    
    // PIMPL
    Gamepad::Gamepad(int controllerIndex) :
		m_pImpl(std::make_unique<Impl>(controllerIndex))
    {
    }
    
	void Gamepad::Update()
    {
	    m_pImpl->Update();
    }
	bool Gamepad::IsPressed(Button button) const
    {
        return m_pImpl->IsPressed(button);
    }
	bool Gamepad::IsDownThisFrame(Button button) const
	{
		return m_pImpl->IsDownThisFrame(button);
	}
    bool Gamepad::IsUpThisFrame(Button button) const
    {
	    return m_pImpl->IsUpThisFrame(button);
    }
}
