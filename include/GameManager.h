#pragma once

#include "Manager.h"
#include "Sprite.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class GameManager : public Manager
{
public:
	GameManager();
	void Update();
	void Display();

private:
};