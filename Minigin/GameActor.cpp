#include "GameActor.h"

using namespace dae;

GameActor::GameActor(const std::string& path) :
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

void GameActor::MoveUp()
{
    m_Transform.SetY(m_Transform.GetY() + m_Speed);
}

void GameActor::MoveDown()
{
    m_Transform.SetY(m_Transform.GetY() - m_Speed);
}

void GameActor::MoveLeft()
{
    m_Transform.SetX(m_Transform.GetX() - m_Speed);
}

void GameActor::MoveRight()
{
    m_Transform.SetX(m_Transform.GetX() + m_Speed);
}

void GameActor::Place()
{
}

void GameActor::Explode()
{
}
