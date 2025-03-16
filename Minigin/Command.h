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

	class MoveUp : public GameActorCommand
	{
	public:
		virtual void Execute() override;
	};

	class MoveDown : public GameActorCommand
	{
	public:
		virtual void Execute() override;
	};

	class MoveLeft : public GameActorCommand
	{
	public:
		virtual void Execute() override;
	};

	class MoveRight : public GameActorCommand
	{
	public:
		virtual void Execute() override;
	};

	class Place : public GameActorCommand
	{
	public:
		virtual void Execute() override;
	};

	class Explode : public GameActorCommand
	{
	public:
		virtual void Execute() override;
	};
}

