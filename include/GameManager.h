#pragma once

#include "Manager.h"
#include "GameScene.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GameManager : public Manager
{
public:
	GameManager();

	GameScene& GetGameScene() { return m_gameScene; }

	void Update();
	void Display();

private:
	GameScene m_gameScene;
};