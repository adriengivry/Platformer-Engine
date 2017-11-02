#pragma once

#include "Object.h"
#include "Sprite.h"

class Actor : public Object
{
public:
	Actor();
	virtual ~Actor();

	Sprite& GetSprite() { return m_sprite; }
	vec4& GetHitbox() { return m_hitbox; }
	vec4 GetHitbox() const { return m_hitbox; }

	bool IsUpdatable() const { return m_isUpdatable; }
	bool IsTickable() const { return m_isTickable; }
	bool IsDrawable() const { return m_isDrawable; }
	
	void SetUpdatable(const bool p_state) { m_isUpdatable = p_state; }
	void SetTickable(const bool p_state) { m_isTickable = p_state; }
	void SetDrawable(const bool p_state) { m_isDrawable = p_state; }

	void SetTexture(const std::string p_path) { m_sprite.SetTexture(p_path); }
	void SetTexture(const gl::Texture2dRef p_texture) { m_sprite.SetTexture(p_texture); }

	void Update();
	void Tick();
	void Draw();

private:
	bool m_isUpdatable;
	bool m_isTickable;
	bool m_isDrawable;

	Sprite m_sprite;
	vec4 m_hitbox;
};