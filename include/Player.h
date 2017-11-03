#pragma once

#include "MovableActor.h"

#define PLAYER_SPEED 500
#define PLAYER_JUMP_FORCE 800
#define PLAYER_SPRITE "rock.png"

class Player : public MovableActor
{
public:
	Player();
	~Player() {}

	void CheckControls(EventManager& p_eventManager);
	void Update(EventManager& p_eventManager, GameInfo& p_gameInfo) override;
};