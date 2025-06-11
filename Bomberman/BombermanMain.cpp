#include <SDL.h>

#pragma once
#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"

#include "FPSComponent.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "RenderComponent.h"
#include "Scene.h"
#include "TrashTheCache.h"
#include "InputManager.h"
#include "GameCommands.h"
#include "GameActor.h"

#include <iostream>

void loadBackground()
{
	
}



void SetInputMappingController(dae::GameActor* actor, int controller)
{
	dae::InputManager::GetInstance().BindCommandToGamepad(controller, dae::InputState::Pressed, dae::Button::DPAD_UP, new dae::Move(actor, glm::vec2{ 0, -1 }));
	dae::InputManager::GetInstance().BindCommandToGamepad(controller, dae::InputState::Pressed, dae::Button::DPAD_DOWN, new dae::Move(actor, glm::vec2{ 0, 1 }));
	dae::InputManager::GetInstance().BindCommandToGamepad(controller, dae::InputState::Pressed, dae::Button::DPAD_LEFT, new dae::Move(actor, glm::vec2{ -1, 0 }));
	dae::InputManager::GetInstance().BindCommandToGamepad(controller, dae::InputState::Pressed, dae::Button::DPAD_RIGHT, new dae::Move(actor, glm::vec2{ 1, 0 }));

	dae::InputManager::GetInstance().BindCommandToGamepad(controller, dae::InputState::DownThisFrame   , dae::Button::A, new dae::Place(actor));
}

void SetInputMappingKeyboard(dae::GameActor* actor)
{
	dae::InputManager::GetInstance().BindCommandToKeyboard( SDL_SCANCODE_UP,		new dae::Move(actor, glm::vec2{ 0, -1 }));
	dae::InputManager::GetInstance().BindCommandToKeyboard( SDL_SCANCODE_DOWN,	new dae::Move(actor, glm::vec2{ 0, 1 }));
	dae::InputManager::GetInstance().BindCommandToKeyboard( SDL_SCANCODE_LEFT,	new dae::Move(actor, glm::vec2{ -1, 0 }));
	dae::InputManager::GetInstance().BindCommandToKeyboard( SDL_SCANCODE_RIGHT, new dae::Move(actor, glm::vec2{ 1, 0 }));

	//dae::InputManager::GetInstance().BindCommandToGamepad(controller, dae::InputState::DownThisFrame, dae::Button::A, new dae::Place(actor));
}

std::vector<std::shared_ptr<dae::GameObject>> SetGameActors()
{
	std::vector<std::shared_ptr<dae::GameObject>> actors;

	// Player 1
	auto Bomberman = std::make_shared<dae::GameObject>();
	Bomberman->AddComponent<dae::GameActor>("Sprites/Bomberman_NoAnim.png");

	auto* bombermanActor = Bomberman->GetComponent<dae::GameActor>();
	bombermanActor->SetPosition(100, 100);
	bombermanActor->SetSpeed(200.f);

	actors.push_back(Bomberman);

	// Set input mapping for Player 1
	SetInputMappingController(bombermanActor, 0);
	SetInputMappingKeyboard(bombermanActor);

	// *********************************************************

	// Player 2
	auto Bomberman2 = std::make_shared<dae::GameObject>();
	Bomberman2->AddComponent<dae::GameActor>("Sprites/Bomberman2_NoAnim.png");

	auto* bombermanActor2 = Bomberman2->GetComponent<dae::GameActor>();
	bombermanActor2->SetPosition(200, 100);
	bombermanActor2->SetSpeed(200.f);

	actors.push_back(Bomberman2);

	// Set input mapping for Player 2
	SetInputMappingController(bombermanActor2, 1);


	

	return actors;
}

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto background = std::make_shared<dae::GameObject>();
	auto backgroundTexture = dae::ResourceManager::GetInstance().LoadTexture("background.tga");
	background->AddComponent<dae::RenderComponent>(backgroundTexture);
	background->SetPosition(0, 0);
	scene.Add(background);

	auto logo = std::make_shared<dae::GameObject>();
	auto logoTexture = dae::ResourceManager::GetInstance().LoadTexture("logo.tga");
	logo->AddComponent<dae::RenderComponent>(logoTexture);
	logo->SetPosition(216, 180);
	scene.Add(logo);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	auto title = std::make_shared<dae::GameObject>();
	std::string titleText = "Programming 4 Assignment";
	title->AddComponent<dae::TextComponent>(titleText, font);
	title->SetPosition(100, 20);
	scene.Add(title);

	auto FPS = std::make_shared<dae::GameObject>();
	FPS->AddComponent<dae::FPSComponent>(font);
	FPS->SetPosition(10, 10);
	FPS->GetComponent<dae::FPSComponent>()->SetSize(20);
	scene.Add(FPS);


	auto livesPlayer1 = std::make_shared<dae::GameObject>();
	std::string playerOneText = "# Player 1  --  Lives: 3 -- Score: 0";
	livesPlayer1->AddComponent<dae::TextComponent>(playerOneText, font);
	livesPlayer1->SetPosition(10, 70);
	livesPlayer1->GetComponent<dae::TextComponent>()->SetSize(18);
	scene.Add(livesPlayer1);

	auto livesPlayer2 = std::make_shared<dae::GameObject>();
	std::string playerTwoText = "# Player 2  --  Lives: 3 -- Score: 0";
	livesPlayer2->AddComponent<dae::TextComponent>(playerTwoText, font);
	livesPlayer2->SetPosition(10, 95);
	livesPlayer2->GetComponent<dae::TextComponent>()->SetSize(18);
	scene.Add(livesPlayer2);
	auto actors = SetGameActors();

	for (auto actor : actors)
	{
		scene.Add(actor);
	}
	
}

int main(int, char* []) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
	return 0;
}