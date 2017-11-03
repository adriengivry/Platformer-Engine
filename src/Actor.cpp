#include "Actor.h"

Actor::Actor() : GameObject()
{
	SetObjectType("ACTOR");

	SetLife(500);
}
