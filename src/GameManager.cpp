#include "GameManager.h"

GameManager::GameManager() : Manager()
{
}

void GameManager::Update()
{
	GetGameScene().Update(GetEventManager());
}

void GameManager::Display()
{
	GetGameScene().Display();
}
