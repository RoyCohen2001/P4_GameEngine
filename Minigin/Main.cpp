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
	title->SetPosition(216, 20);
	scene.Add(title);
}


int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}