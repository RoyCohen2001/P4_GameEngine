#pragma once
#include "Transform.h"
#include "Texture2D.h"
#include "Component.h"

namespace dae {
	class GameActor
    {
    public:
        GameActor(const std::string& path);
        ~GameActor() = default;

        void Update(float deltaTime);

        // Set variables of the actor
        void SetSpeed(float speed);
        void SetPosition(float x, float y);

        // Move the actor
        void MoveUp();
        void MoveDown();
        void MoveLeft();
        void MoveRight();

        // Executables
        void Place();
        void Explode();

    private:
        Transform m_Transform;
        Texture2D* m_Texture;
        float m_Speed;
    };
}
