#include "GameManager.h"

GameManager::GameManager() : Manager()
{
	SetGameScene(new GameScene(GetEventManager(), GetGameInfo()));
	SetUserInterface(new UserInterface(GetEventManager(), GetGameInfo(), GetGameScene()));
	GetGameScene().Setup();
}

GameManager::~GameManager()
{
	delete &GetGameScene();
}

void GameManager::Update()
{
	GetGameScene().Update();
	GetUserInterface().Update();
}

void GameManager::Display()
{
	GetGameScene().Draw();
	GetUserInterface().Draw();
}
