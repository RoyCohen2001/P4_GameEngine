#pragma once

namespace dae
{
    class GameObject;

    class Component
    {
    public:
        virtual void Update(float deltaTime) = 0;
        virtual void Render() const = 0;

        GameObject* GetOwner() const { return m_pOwner; }

        Component() = default;
        virtual ~Component() {};
        Component(const Component& other) = delete;
        Component(Component&& other) = delete;
        Component& operator=(const Component& other) = delete;
        Component& operator=(Component&& other) = delete;

    private:
        GameObject* m_pOwner{ nullptr };
    };
}
