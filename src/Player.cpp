#include "Player.h"

Player::Player() : MovableActor()
{
	SetObjectType("PLAYER");

	SetStuckInScreen(true);
	SetPhysicBody(true);

	GetAnimations().WALK.LoadFolder("Player/Walking/", 18, "png");
	GetAnimations().STAND.LoadFolder("Player/Idle/", 12, "png");
	GetAnimations().DIE.LoadFolder("Player/Dying/", 15, "png");
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
		vy = -PLAYER_JUMP_FORCE;
		SetJumping(true);
	}

	SetVelocity(vx, vy);
}

void Player::Update(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
	CheckControls(p_eventManager);

	MovableActor::Update(p_eventManager, p_gameInfo);
}

void Player::Tick(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
	if (!IsAlive() && GetCurrentAnimation() == &GetAnimations().DIE && GetCurrentAnimation()->IsEnded())
		p_gameInfo.m_run = false;
}
