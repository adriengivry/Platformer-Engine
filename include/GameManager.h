#pragma once

#include "Manager.h"
#include "GameScene.h"
#include "EventManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GameManager : public Manager
{
public:
	GameManager();

	GameScene& GetGameScene() { return m_gameScene; }
	EventManager& GetEventManager() { return m_eventManager; }

	void Update();
	void Display();

private:
	GameScene m_gameScene;
	EventManager m_eventManager;
};