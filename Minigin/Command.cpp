#include "Command.h"

using namespace dae;

GameActorCommand::GameActorCommand(GameActor* actor):
	m_actor(actor)
{
}

GameActorCommand::~GameActorCommand()
{
	delete m_actor;
	m_actor = nullptr;
}

void dae::Move::Execute()
{
}

void Place::Execute()
{
	GetGameActor()->Place();
}

void Explode::Execute()
{
	GetGameActor()->Explode();
}

