#include "FPSComponent.h"

dae::FPSComponent::FPSComponent(GameObject* owner):
	Component(owner),
	m_FrameCount(0),
	m_FPSTimer(std::chrono::high_resolution_clock::now())
{
}

void dae::FPSComponent::Update(float /*deltaTime*/)
{
	++m_FrameCount;
	const auto current_time = std::chrono::high_resolution_clock::now();
	const auto duration = std::chrono::duration<float, std::milli>(current_time - m_FPSTimer).count();
	if (duration >= 1000.0f)
	{
		m_FrameCount = 0;
		m_FPSTimer = current_time;
	}
}
