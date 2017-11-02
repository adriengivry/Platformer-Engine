#pragma once

#include "Manager.h"

class GameScene : public Manager
{
public:
	GameScene();
	~GameScene();

	void Update();
	void Display();
};