#include "Sprite.h"

Sprite::Sprite()
{
	const auto img = loadImage(loadAsset("character.png"));
	m_texture = gl::Texture2d::create(img);
	m_position = vec2(0, 0);
	m_scale = vec2(1, 1);
}

void Sprite::SetPosition(const float p_posX, const float p_posY)
{
	m_position.x = p_posX;
	m_position.y = p_posY;
}

void Sprite::SetPosition(const vec2& p_position)
{
	m_position = p_position;
}

void Sprite::SetScale(const float p_scaleX, const float p_scaleY)
{
	m_scale.x = p_scaleX;
	m_scale.y = p_scaleY;
}

void Sprite::SetScale(const vec2& p_scale)
{
	m_scale = p_scale;
}

void Sprite::Move(const float p_x, const float p_y)
{
	m_position.x += p_x;
	m_position.y += p_y;
}

void Sprite::Draw() const
{
	gl::pushModelMatrix();
	gl::translate(GetPosition().y, GetPosition().x);
	gl::scale(GetScale().x, GetScale().y);
	gl::draw(m_texture);
	gl::popModelMatrix();
}
