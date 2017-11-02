#include "Actor.h"

Actor::Actor() : Object()
{
	SetUpdatable(true);
	SetTickable(true);
	SetDrawable(true);
}

Actor::~Actor()
{
}

void Actor::Update()
{
	if (IsUpdatable())
	{
		if (IsTickable())
			Tick();

		if (IsDrawable())
			Draw();
	}
}

void Actor::Tick()
{
	// TODO: Actor tick
}

void Actor::Draw()
{
	GetSprite().Draw();
}
