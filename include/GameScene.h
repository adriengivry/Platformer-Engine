#pragma once

#include <list>

#include "Manager.h"
#include "Actor.h"
#include "EventManager.h"

class GameScene : public Manager
{
public:
	GameScene();
	~GameScene();

	std::list<Actor*>& GetActors() { return m_actors; }

	void Setup();
	void Update(EventManager& p_eventManager);
	void Draw();
	void DrawGrid() const;

private:
	std::list<Actor*> m_actors;
};