#include "Hitbox.h"

Hitbox::Hitbox(const float p_x, const float p_y, const float p_sizeX, const float p_sizeY)
{
	m_position.x = p_x;
	m_position.y = p_y;
	m_size.x = p_sizeX;
	m_size.y = p_sizeY;
}

void Hitbox::SetPosition(const float p_x, const float p_y)
{
	m_position.x = p_x;
	m_position.y = p_y;
}

void Hitbox::SetSize(const float p_sizeX, const float p_sizeY)
{
	m_size.x = p_sizeX;
	m_size.y = p_sizeY;
}

bool Hitbox::Intersect(const Hitbox& p_otherHitbox)
{
	const auto x1 = GetPosition().x;
	const auto y1 = GetPosition().y;
	const auto w1 = GetSize().x;
	const auto h1 = GetSize().y;

	const auto x2 = p_otherHitbox.GetPosition().x;
	const auto y2 = p_otherHitbox.GetPosition().y;
	const auto w2 = p_otherHitbox.GetSize().x;
	const auto h2 = p_otherHitbox.GetSize().y;

	return x1 + w1 >= x2 && x1 <= x2 + w2 && y1 + h1 >= y2 && y1 <= y2 + h2;
}

bool Hitbox::Intersect(const glm::vec2& p_point)
{
	const auto x1 = GetPosition().x;
	const auto y1 = GetPosition().y;
	const auto w1 = GetSize().x;
	const auto h1 = GetSize().y;

	const float x2 = p_point.x;
	const float y2 = p_point.y;

	return x1 + w1 >= x2 && x1 <= x2 && y1 + h1 >= y2 && y1 <= y2;
}
