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
	}
}

void Actor::Tick()
{
	// TODO: Actor tick
}

void Actor::Draw()
{
	if (IsDrawable())
	{
		GetSprite().Draw();
	}
}
