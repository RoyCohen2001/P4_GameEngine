#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::FixedUpdate(float /*fixedTimeStep*/) {}

void dae::GameObject::Update(float deltaTime)
{
    for (const auto& component : m_Components)
    {
        component->Update(deltaTime);
    }
}

void dae::GameObject::Render() const
{
    for (const auto& component : m_Components)
    {
        component->Render();
    }
}

void dae::GameObject::SetPosition(float x, float y)
{
    m_Transform.SetPosition(x, y, 0.0f);
}
