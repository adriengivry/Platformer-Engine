#include "MovableActor.h"

MovableActor::MovableActor() : Actor()
{
	SetObjectType("MOVABLE_ACTOR");

	SetMovable(true);
	SetStuckInScreen(false);
	SetPhysicBody(false);
	SetJumping(true);
}

void MovableActor::Update(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
	if (IsPhysicBody())
		ApplyPhysics();

	if (IsMovable())
		Move(GetVelocity().x * p_gameInfo.m_deltaTime, GetVelocity().y * p_gameInfo.m_deltaTime);

	Actor::Update(p_eventManager, p_gameInfo);
}

void MovableActor::Move(const float p_x, const float p_y)
{
	if (IsMovable())
	{
		GetHitbox().GetPosition().x += p_x;
		GetHitbox().GetPosition().y += p_y;

		if (IsStuckInScreen())
		{
			if (GetHitbox().GetPosition().x < 0)
				GetHitbox().GetPosition().x = 0;

			if (GetHitbox().GetPosition().y < 0)
			{
				GetHitbox().GetPosition().y = 0;
				if (IsPhysicBody())
					GetVelocity().y = 0;
			}

			if (GetHitbox().GetPosition().x + GetHitbox().GetSize().x > WINDOW_WIDTH)
				GetHitbox().GetPosition().x = WINDOW_WIDTH - GetHitbox().GetSize().x;

			if (GetHitbox().GetPosition().y + GetHitbox().GetSize().y > WINDOW_HEIGHT)
			{
				GetHitbox().GetPosition().y = WINDOW_HEIGHT - GetHitbox().GetSize().y;
				if (IsPhysicBody())
				{
					GetVelocity().y = 0;
					SetJumping(false);
				}
			}
		}
	}
}

void MovableActor::ApplyPhysics()
{
	GetVelocity().y += PHYSIC_GRAVITY;
}
