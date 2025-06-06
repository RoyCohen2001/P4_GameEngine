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



void SetInputMapping(dae::GameActor* actor)
{
	auto* moveCommand = new dae::Move(actor);
	auto* placeCommand = new dae::Place(actor);

	dae::InputManager::GetInstance().BindCommandToGamepad(dae::Button::DPAD_UP, moveCommand);
	dae::InputManager::GetInstance().BindCommandToGamepad(dae::Button::DPAD_DOWN, moveCommand);
	dae::InputManager::GetInstance().BindCommandToGamepad(dae::Button::DPAD_RIGHT, moveCommand);
	dae::InputManager::GetInstance().BindCommandToGamepad(dae::Button::DPAD_LEFT, moveCommand);

	dae::InputManager::GetInstance().BindCommandToGamepad(dae::Button::A, placeCommand);
}

std::vector<std::shared_ptr<dae::GameObject>> SetGameActors()
{
	std::vector<std::shared_ptr<dae::GameObject>> actors;

	auto Bomberman = std::make_shared<dae::GameObject>();
	Bomberman->AddComponent<dae::GameActor>("Sprites/Bomberman.png");
	Bomberman->SetPosition(100, 100);

	auto* bombermanActor = Bomberman->GetComponent<dae::GameActor>();
	SetInputMapping(bombermanActor);

	actors.push_back(Bomberman);

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