#include "Sprite.h"


Sprite::Sprite(const std::string p_imagePath, const float p_x, const float p_y, const float p_scaleX, const float p_scaleY)
{
	if (p_imagePath != "")
		SetTexture(p_imagePath);

	SetPosition(p_x, p_y);
	SetScale(p_scaleX, p_scaleY);
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

void Sprite::SetTexture(const std::string p_path)
{
	const auto img = loadImage(loadAsset(p_path));
	SetTexture(gl::Texture2d::create(img));
}

void Sprite::Move(const float p_x, const float p_y)
{
	m_position.x += p_x;
	m_position.y += p_y;
}

void Sprite::Draw() const
{
	if (GetTexture() && SHOW_SPRITE)
	{
		gl::pushModelMatrix();
		gl::translate(GetPosition().x, GetPosition().y);
		gl::scale(GetScale().x, GetScale().y);
		gl::draw(GetTexture());
		gl::popModelMatrix();
	}
}
