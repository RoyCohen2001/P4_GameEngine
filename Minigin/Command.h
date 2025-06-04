#pragma once
#include "GameActor.h"

namespace dae {
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void Execute() = 0;
	};

	class GameActorCommand : public Command {
		GameActor* m_actor;
	protected:
		GameActor* GetGameActor() const { return m_actor; }
	public:
		GameActorCommand(GameActor* actor);
		virtual ~GameActorCommand();
	};

	class Move: public GameActorCommand
	{
	public:
		Move(GameActor* actor) : GameActorCommand(actor) {}

		void Execute() override
		{
			GetGameActor()->Move();
		}
	};
	
	//class Place : public GameActorCommand
	//{
	//public:
	//	void Execute() override
	//	{
	//		GetGameActor()->Place();
	//	}
	//};
	//
	//class Explode : public GameActorCommand
	//{
	//public:
	//	void Execute() override
	//	{
	//		GetGameActor()->Explode();
	//	}
	//};
}

