#pragma once
#include <memory>

#include "Transform.h"
#include "Texture2D.h"
#include "Component.h"

namespace dae {
	class GameActor final : public Component
    {
    public:
        GameActor(GameObject* owner, const std::string& path);

        void Update(float deltaTime) override;
        void Render() const override;

        // Set variables of the actor
        void SetSpeed(float speed);
        void SetPosition(float x, float y);

        // Move the actor
        void Move();

        // Executables
        void Place();
        void Explode();

        virtual ~GameActor() = default;
        GameActor(const GameActor& other) = delete;
        GameActor(GameActor&& other) = delete;
        GameActor& operator=(const GameActor& other) = delete;
        GameActor& operator=(GameActor&& other) = delete;

    private:
        Transform m_Transform;
        std::shared_ptr<Texture2D> m_Texture;
        float m_Speed;
    };
}
