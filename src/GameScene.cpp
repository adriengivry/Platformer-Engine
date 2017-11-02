#include "GameScene.h"

GameScene::GameScene() : Manager()
{
	Actor* character = new Actor;
	character->SetTexture("character.png");
	GetActors().push_back(character);
}

GameScene::~GameScene()
{
}

void GameScene::Update(EventManager& p_eventManager)
{
	
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		(*iterator)->Update(p_eventManager);
}

void GameScene::Display()
{
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		(*iterator)->Draw();
}
