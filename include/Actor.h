#pragma once

#include "GameObject.h"

class Actor : public GameObject
{
public:
	Actor();
	~Actor() {}

	void Tick(EventManager& p_eventManager, GameInfo& p_gameInfo) override
	{
		const int speed = 500;

		if (p_eventManager.GetEvent("MOVE_RIGHT").IsOn())
			Move(speed * p_gameInfo.m_deltaTime, 0);

		if (p_eventManager.GetEvent("MOVE_LEFT").IsOn())
			Move(-speed * p_gameInfo.m_deltaTime, 0);

		if (p_eventManager.GetEvent("MOVE_UP").IsOn())
			Move(0, -speed * p_gameInfo.m_deltaTime);

		if (p_eventManager.GetEvent("MOVE_DOWN").IsOn())
			Move(0, speed * p_gameInfo.m_deltaTime);
	}
};