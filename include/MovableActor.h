#pragma once

#include "Actor.h"

#define DEFAULT_VELOCITY 500
#define PHYSIC_GRAVITY 20

enum Direction
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT
};

struct Animations
{
	Animation WALK;
	Animation STAND;
	Animation DIE;
};

class MovableActor : public Actor
{
public:
	MovableActor();
	~MovableActor() {}

	bool IsMovable() const { return m_isMovable; }
	bool IsStuckInScreen() const { return m_isStuckInScreen; }
	bool IsPhysicBody() const { return m_isPhysicBody; }
	bool IsJumping() const { return m_isJumping; }
	bool IsAnimated() const { return GetCurrentAnimation() && !GetCurrentAnimation()->IsEmpty() && GetCurrentAnimationSprite(); }
	
	void SetMovable(const bool p_state) { m_isMovable = p_state; }
	void SetStuckInScreen(const bool p_state) { m_isStuckInScreen = p_state; }
	void SetPhysicBody(const bool p_state) { m_isPhysicBody = p_state; }
	void SetVelocity(const float p_vx, const float p_vy) { m_velocity.x = p_vx; m_velocity.y = p_vy; }
	void SetJumping(const bool p_state) { m_isJumping = p_state; }
	void SetDirection(const uint8_t p_direction) { m_direction = p_direction; }
	void SetCurrentAnimation(Animation* p_animation) { m_currentAnimation = p_animation; }

	void AddVelocity(const float p_vx, const float p_vy) { m_velocity.x += p_vx; m_velocity.y += p_vy; }

	vec2& GetVelocity() { return m_velocity; }
	uint8_t& GetDirection() { return m_direction; }
	Animation* GetCurrentAnimation() const { return m_currentAnimation; }
	Animations& GetAnimations() { return m_animations; }
	Sprite* GetCurrentAnimationSprite() const { return GetCurrentAnimation()->GetCurrentSprite();  }

	void ChooseTheRightAnimation();

	void Update(EventManager& p_eventManager, GameInfo& p_gameInfo) override;
	void Move(const float p_x, const float p_y);
	void ApplyPhysics();

	void DrawSprite() override;

private:
	bool m_isMovable;
	bool m_isStuckInScreen;
	bool m_isPhysicBody;
	bool m_isJumping;

	Animations m_animations;
	Animation* m_currentAnimation;

	vec2 m_velocity;

	uint8_t m_direction;
};