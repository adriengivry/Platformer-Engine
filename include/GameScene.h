#pragma once

#include <list>

#include "Manager.h"
#include "Player.h"
#include "EventManager.h"
#include "GameInfo.h"

class GameScene : public Manager
{
public:
	GameScene(EventManager& p_eventManager, GameInfo& p_gameInfo);
	~GameScene();

	EventManager& GetEventManager() const { return m_eventManager; }
	GameInfo& GetGameInfo() const { return m_gameInfo; }

	std::map<int, Actor*>& GetActors() { return m_actors; }

	void AddActor(const int p_zBuffer, Actor* p_actor) { GetActors().insert(std::pair<int, Actor*>(p_zBuffer, p_actor)); }

	void Setup();
	void Update();
	void Draw();
	void DrawGrid() const;

private:
	std::map<int, Actor*> m_actors;
	EventManager& m_eventManager;
	GameInfo& m_gameInfo;
};