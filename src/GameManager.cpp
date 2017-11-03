#include "GameManager.h"

GameManager::GameManager() : Manager()
{
	GetGameScene().Setup();		
}

void GameManager::Update()
{
	GetGameScene().Update(GetEventManager());
}

void GameManager::Display()
{
	GetGameScene().Draw();
}
