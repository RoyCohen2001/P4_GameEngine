#include "GameActor.h"

using namespace dae;

GameActor::GameActor(GameObject* owner, const std::string& path) :
	Component(owner),
    m_Speed{ 10.0f },
    m_Transform{},
    m_Texture{ new Texture2D(path) }
{
}

void GameActor::Update(float /*deltaTime*/)
{
    // Update logic here
}

void GameActor::SetSpeed(float speed)
{
    m_Speed = speed;
}

void GameActor::SetPosition(float x, float y)
{
    m_Transform.SetPosition(x, y, 0.0f);
}

void dae::GameActor::Move()
{
	
}

void GameActor::Place()
{
}

void GameActor::Explode()
{
}
