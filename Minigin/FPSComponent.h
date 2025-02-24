#pragma once
#include "Component.h"
#include "GameObject.h"
#include <chrono>

namespace dae
{
	class FPSComponent final : public Component
	{
	public:
		FPSComponent(GameObject* owner);
		void Update(float deltaTime) override;
		
	private:
		int m_FrameCount;
		std::chrono::high_resolution_clock::time_point m_FPSTimer;
	};
}

