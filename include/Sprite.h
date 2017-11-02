#pragma once

#include <string>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Component.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sprite : public Component
{
public:
	explicit Sprite(const std::string p_imagePath = "", const float p_x = 0, const float p_y = 0, const float p_scaleX = 1, const float p_scaleY = 1);
	virtual ~Sprite() {}

	vec2& GetPosition() { return m_position; }
	vec2 GetPosition() const { return m_position; }
	vec2& GetScale() { return m_scale; }
	vec2 GetScale() const { return m_scale; }
	gl::Texture2dRef GetTexture() const { return m_texture; }

	void SetPosition(const float p_posX, const float p_posY);
	void SetPosition(const vec2& p_position);
	void SetScale(const float p_scaleX, const float p_scaleY);
	void SetScale(const vec2& p_scale);
	void SetTexture(const std::string p_path);
	void SetTexture(const gl::Texture2dRef p_texture) { m_texture = p_texture; }

	void Move(const float p_x, const float p_y);

	void Draw() const;

private:
	vec2 m_position;
	vec2 m_scale;

	gl::Texture2dRef m_texture;
};

