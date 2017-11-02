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

void GameScene::Update()
{
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		(*iterator)->Update();
}

void GameScene::Display()
{
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		(*iterator)->Draw();
}
