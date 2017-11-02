#pragma once

#include "cinder/app/App.h"

#include "Component.h"

class Hitbox : public Component
{
public:
	explicit Hitbox(const float p_x = 0, const float p_y = 0, const float p_sizeX = 0, const float p_sizeY = 0);
	~Hitbox() {}

	glm::vec2& GetPosition() { return m_position; }
	glm::vec2 GetPosition() const { return m_position; }
	glm::vec2& GetSize() { return m_size; }
	glm::vec2 GetSize() const { return m_size; }

	void SetPosition(const float p_x, const float p_y);
	void SetPosition(const glm::vec2& p_position) { m_position = p_position; }

	void SetSize(const float p_sizeX, const float p_sizeY);
	void SetSize(const glm::vec2& p_size) { m_size = p_size; }

	bool Intersect(const glm::vec2& p_point);
	bool Intersect(const Hitbox& p_otherHitbox);

private:
	glm::vec2 m_position;
	glm::vec2 m_size;
};