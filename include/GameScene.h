#pragma once

#include <list>

#include "Manager.h"
#include "Actor.h"
#include "EventManager.h"
#include "GameInfo.h"

class GameScene : public Manager
{
public:
	GameScene(EventManager& p_eventManager, GameInfo& p_gameInfo);
	~GameScene();

	EventManager& GetEventManager() const { return m_eventManager; }
	GameInfo& GetGameInfo() const { return m_gameInfo; }

	std::list<Actor*>& GetActors() { return m_actors; }

	void Setup();
	void Update();
	void Draw();
	void DrawGrid() const;

private:
	std::list<Actor*> m_actors;
	EventManager& m_eventManager;
	GameInfo& m_gameInfo;
};