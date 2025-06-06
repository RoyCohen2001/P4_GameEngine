#pragma once
#include "Command.h"
#include "GameActor.h"

namespace dae {

	class GameCommands : public Command
	{
		GameActor* m_actor;
	protected:
		GameActor* GetGameActor() const { return m_actor; }
	public:
		GameCommands(GameActor* actor);
		virtual ~GameCommands();
	};

	class Move : public GameCommands
	{
	public:
		Move(GameActor* actor) : GameCommands(actor) {}

		void Execute() override
		{
			GetGameActor()->Move();
		}
	};

	class Place : public GameCommands
	{
	public:
		Place(GameActor* actor) : GameCommands(actor) {}

		void Execute() override
		{
			GetGameActor()->Place();
		}
	};
	
	class Explode : public GameCommands
	{
	public:
		Explode(GameActor* actor) : GameCommands(actor) {}

		void Execute() override
		{
			GetGameActor()->Explode();
		}
	};

}