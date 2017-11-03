#pragma once

#include "GameObject.h"

class Actor : public GameObject
{
public:
	Actor();
	~Actor() {}

	void Tick() override
	{
		Move(1, 0);
	}

	void OnMouseLeftclick() override
	{
		exit(0);
	}

};