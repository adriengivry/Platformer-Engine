#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sprite
{
public:
	Sprite();
	~Sprite() {}

	vec2& GetPosition() { return m_position; }
	vec2 GetPosition() const { return m_position; }
	vec2& GetScale() { return m_scale; }
	vec2 GetScale() const { return m_scale; }

	void SetPosition(const float p_posX, const float p_posY);
	void SetPosition(const vec2& p_position);

	void SetScale(const float p_scaleX, const float p_scaleY);
	void SetScale(const vec2& p_scale);

	void Move(const float p_x, const float p_y);

	void Draw() const;

private:
	vec2 m_position;
	vec2 m_scale;

	gl::Texture2dRef m_texture;
};

