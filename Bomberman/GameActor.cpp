#include "GameActor.h"
#include "ResourceManager.h"
#include <iostream>

#include "RenderComponent.h"

using namespace dae;

GameActor::GameActor(GameObject* owner, const std::string& path) :
	Component(owner),
    m_Speed{ 10.0f },
    m_Transform{},
	m_Texture{ ResourceManager::GetInstance().LoadTexture(path) }
{
    
}

void GameActor::Update(float /*deltaTime*/)
{
    // Update logic here

    
}

void GameActor::Render() const
{
    if (!m_Texture) return;

	auto renderComponent = dae::RenderComponent(GetOwner(), m_Texture);
    renderComponent.Render();
}

void GameActor::SetSpeed(float speed)
{
    m_Speed = speed;
}

void GameActor::SetPosition(float x, float y)
{
    m_Transform.SetPosition(x, y, 0.0f);
}

void GameActor::Move()
{
	// Implement movement logic here
	// For example, you could update the position based on speed and direction
	// m_Transform.SetPosition(m_Transform.GetPosition().x + m_Speed * deltaTime, m_Transform.GetPosition().y);
	std::cout << "Moving" << std::endl;
}

void GameActor::Place()
{
}

void GameActor::Explode()
{
}
