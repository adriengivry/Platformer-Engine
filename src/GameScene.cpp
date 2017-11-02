#include "GameScene.h"

GameScene::GameScene() : Manager()
{
	
}

GameScene::~GameScene()
{
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		delete *iterator;
}

void GameScene::Setup()
{
	Actor* character = new Actor;
	character->SetTexture("character.png");
	GetActors().push_back(character);
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
