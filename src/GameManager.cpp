#include "GameManager.h"

GameManager::GameManager() : Manager()
{
}

void GameManager::Update()
{
	GetGameScene().Update();
}

void GameManager::Display()
{
	GetGameScene().Display();
}
