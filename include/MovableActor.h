#pragma once

#include "Actor.h"

#define DEFAULT_VELOCITY 500
#define PHYSIC_GRAVITY 20

class MovableActor : public Actor
{
public:
	MovableActor();
	~MovableActor() {}

	bool IsMovable() const { return m_isMovable; }
	bool IsStuckInScreen() const { return m_isStuckInScreen; }
	bool IsPhysicBody() const { return m_isPhysicBody; }
	bool IsJumping() const { return m_isJumping; }
	
	void SetMovable(const bool p_state) { m_isMovable = p_state; }
	void SetStuckInScreen(const bool p_state) { m_isStuckInScreen = p_state; }
	void SetPhysicBody(const bool p_state) { m_isPhysicBody = p_state; }
	void SetVelocity(const float p_vx, const float p_vy) { m_velocity.x = p_vx; m_velocity.y = p_vy; }
	void SetJumping(const bool p_state) { m_isJumping = p_state; }

	void AddVelocity(const float p_vx, const float p_vy) { m_velocity.x += p_vx; m_velocity.y += p_vy; }

	vec2& GetVelocity() { return m_velocity; }

	void Update(EventManager& p_eventManager, GameInfo& p_gameInfo) override;
	void Move(const float p_x, const float p_y);
	void ApplyPhysics();

private:
	bool m_isMovable;
	bool m_isStuckInScreen;
	bool m_isPhysicBody;
	bool m_isJumping;

	vec2 m_velocity;
};