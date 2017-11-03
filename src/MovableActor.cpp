#include "MovableActor.h"

MovableActor::MovableActor() : Actor()
{
	SetObjectType("MOVABLE_ACTOR");

	SetMovable(true);
	SetStuckInScreen(false);
	SetPhysicBody(false);
	SetJumping(true);

	GetAnimations().STAND.SetAnimationSpeed(0.05f);
	GetAnimations().WALK.SetAnimationSpeed(0.05f);
	GetAnimations().DIE.SetAnimationSpeed(0.05f);
	GetAnimations().DIE.SetLoop(false);

	SetCurrentAnimation(&GetAnimations().STAND);
}

void MovableActor::ChooseTheRightAnimation()
{
	if (!IsAlive())
	{
		SetCurrentAnimation(&GetAnimations().DIE);
		return;
	}

	if (IsJumping())
		SetCurrentAnimation(&GetAnimations().STAND);
	else
	{
		if (GetVelocity().x != 0)
			GetAnimations().WALK.SetAnimationSpeed(10 / abs(GetVelocity().x));

		if (GetVelocity().x != 0)
			SetCurrentAnimation(&GetAnimations().WALK);
		else
			SetCurrentAnimation(&GetAnimations().STAND);
	}
}

void MovableActor::Update(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
	if (IsPhysicBody())
		ApplyPhysics();

	if (IsMovable())
		Move(GetVelocity().x * p_gameInfo.m_deltaTime, GetVelocity().y * p_gameInfo.m_deltaTime);

	ChooseTheRightAnimation();

	if (GetCurrentAnimation())
		GetCurrentAnimation()->Update(p_gameInfo);

	if (GetVelocity().x > 0)
		SetDirection(DIRECTION_RIGHT);
	else if (GetVelocity().x < 0)
		SetDirection(DIRECTION_LEFT);

	Actor::Update(p_eventManager, p_gameInfo);
}

void MovableActor::Move(const float p_x, const float p_y)
{
	if (IsMovable())
	{
		if (IsAlive())
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

void MovableActor::DrawSprite()
{
	if (GetDirection() == DIRECTION_LEFT)
	{
		GetSprite().SetVerticalFlip(true);
		if (IsAnimated())
			GetCurrentAnimationSprite()->SetVerticalFlip(true);
	}
	else if (GetDirection() == DIRECTION_RIGHT)
	{
		GetSprite().SetVerticalFlip(false);
		if (IsAnimated())
			GetCurrentAnimationSprite()->SetVerticalFlip(false);
	}	

	if (IsAnimated())
	{
		MergeTextureToHitbox(*GetCurrentAnimationSprite());
		GetCurrentAnimationSprite()->Draw();
	}
	else
		Actor::DrawSprite();
}
