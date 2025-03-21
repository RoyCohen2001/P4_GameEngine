#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextComponent.h"
#include "RenderComponent.h"
#include "Scene.h"
#include "TrashTheCache.h"

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
	title->AddComponent<dae::TextComponent>("Programming 4 Assignment", font);
	title->SetPosition(100, 20);
	scene.Add(title);


	auto livesPlayer1 = std::make_shared<dae::GameObject>();
	livesPlayer1->AddComponent<dae::TextComponent>("# Player 1  --  Lives: 3 -- Score: 0", font);
	livesPlayer1->SetPosition(10, 70);	
	livesPlayer1->GetComponent<dae::TextComponent>()->SetSize(18);
	scene.Add(livesPlayer1);

	auto livesPlayer2 = std::make_shared<dae::GameObject>();
	livesPlayer2->AddComponent<dae::TextComponent>("# Player 2  --  Lives: 3 -- Score: 0", font);
	livesPlayer2->SetPosition(10, 95);
	livesPlayer2->GetComponent<dae::TextComponent>()->SetSize(18);
	scene.Add(livesPlayer2);

	//ttc::TrashTheCache trash;
	//trash.RunIntegerBenchmark();
	//trash.RunGameObjectBenchmark();
	//trash.RunGameObjectAltBenchmark();
}


int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}