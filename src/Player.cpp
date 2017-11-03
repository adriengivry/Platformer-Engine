#include "Player.h"

Player::Player() : MovableActor()
{
	SetTexture(PLAYER_SPRITE);
	SetStuckInScreen(true);
	SetPhysicBody(true);
}

void Player::CheckControls(EventManager& p_eventManager)
{
	const float speed = PLAYER_SPEED;
	float vx = 0;
	float vy = GetVelocity().y;

	if (p_eventManager.GetEvent("MOVE_RIGHT").IsOn())
		vx += speed;

	if (p_eventManager.GetEvent("MOVE_LEFT").IsOn())
		vx += -speed;

	if (p_eventManager.GetEvent("MOVE_DOWN").IsOn())
		vy += speed;

	if (p_eventManager.GetEvent("JUMP").IsOn() && !IsJumping())
	{
		vy += -PLAYER_JUMP_FORCE;
		SetJumping(true);
	}

	SetVelocity(vx, vy);
}

void Player::Update(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
	CheckControls(p_eventManager);

	MovableActor::Update(p_eventManager, p_gameInfo);
}
