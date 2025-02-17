#pragma once

namespace dae
{
    class GameObject;

    class Component
    {
    public:
        virtual ~Component() = default;
        virtual void Update(float deltaTime) = 0;
        virtual void Render() const = 0;

        void SetOwner(GameObject* owner) { m_Owner = owner; }
        GameObject* GetOwner() const { return m_Owner; }

    private:
        GameObject* m_Owner{ nullptr };
    };
}
