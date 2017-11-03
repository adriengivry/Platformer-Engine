#pragma once

#include "Manager.h"
#include "GameScene.h"
#include "EventManager.h"
#include "GameInfo.h"
#include "UserInterface.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GameManager : public Manager
{
public:
	GameManager();
	~GameManager();

	GameScene& GetGameScene() const { return *m_gameScene; }
	EventManager& GetEventManager() { return m_eventManager; }
	GameInfo& GetGameInfo() { return m_gameInfo; }
	UserInterface& GetUserInterface() const { return *m_userInterface; }

	void SetGameScene(GameScene* p_gameScene) { m_gameScene = p_gameScene; }
	void SetUserInterface(UserInterface* p_userInterface) { m_userInterface = p_userInterface; }

	void Update();
	void Display();

private:
	GameScene* m_gameScene;
	UserInterface* m_userInterface;
	EventManager m_eventManager;
	GameInfo m_gameInfo;
};