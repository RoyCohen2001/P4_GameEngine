#include "Command.h"

GameActorCommand::GameActorCommand(GameActor* actor):
	m_actor(actor)
{
}

GameActorCommand::~GameActorCommand()
{
	delete m_actor;
	m_actor = nullptr;
}

void MoveUp::Execute()
{
	GetGameActor()->MoveUp();
}

void MoveDown::Execute()
{
	GetGameActor()->MoveDown();
}

void MoveLeft::Execute()
{
	GetGameActor()->MoveLeft();
}

void MoveRight::Execute()
{
	GetGameActor()->MoveRight();
}

void Place::Execute()
{
	GetGameActor()->Place();
}

void Explode::Execute()
{
	GetGameActor()->Explode();
}
