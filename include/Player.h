#pragma once

#include "MovableActor.h"
#include "Animation.h"

#define PLAYER_SPEED 500
#define PLAYER_JUMP_FORCE 1600

class Player : public MovableActor
{
public:
	Player();
	~Player() {}

	void CheckControls(EventManager& p_eventManager);
	void Update(EventManager& p_eventManager, GameInfo& p_gameInfo) override;
	void Tick(EventManager& p_eventManager, GameInfo& p_gameInfo) override;
	void OnMouseLeftclick(EventManager& p_eventManager, GameInfo& p_gameInfo) override;
};