#pragma once

#include <list>

#include "Manager.h"
#include "Actor.h"

class GameScene : public Manager
{
public:
	GameScene();
	~GameScene();

	std::list<Actor*>& GetActors() { return m_actors; }

	void Update();
	void Display();

private:
	std::list<Actor*> m_actors;
};