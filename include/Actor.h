#pragma once

#include "Object.h"
#include "Sprite.h"
#include "EventManager.h"
#include "Hitbox.h"

class Actor : public Object
{
public:
	Actor();
	virtual ~Actor();

	Sprite& GetSprite() { return m_sprite; }
	Hitbox& GetHitbox() { return m_hitbox; }
	Hitbox GetHitbox() const { return m_hitbox; }

	bool IsUpdatable() const { return m_isUpdatable; }
	bool IsTickable() const { return m_isTickable; }
	bool IsDrawable() const { return m_isDrawable; }
	bool IsHoverable() const { return m_isHoverable; }
	bool IsClickable() const { return m_isClickable; }

	bool IsHovered(EventManager& p_eventManager) const;
	
	void SetUpdatable(const bool p_state) { m_isUpdatable = p_state; }
	void SetTickable(const bool p_state) { m_isTickable = p_state; }
	void SetDrawable(const bool p_state) { m_isDrawable = p_state; }
	void SetHoverable(const bool p_state) { m_isHoverable = p_state; }
	void SetClickable(const bool p_state) { m_isClickable = p_state; }

	void SetTexture(const std::string p_path) { m_sprite.SetTexture(p_path); }
	void SetTexture(const gl::Texture2dRef p_texture) { m_sprite.SetTexture(p_texture); }

	void Update(EventManager& p_eventManager);
	void Tick();
	void Draw();
	void OnMouseover();
	void OnMouseLeftclick();
	void OnMouseRightClick();

private:
	bool m_isUpdatable;
	bool m_isTickable;
	bool m_isDrawable;
	bool m_isHoverable;
	bool m_isClickable;

	Sprite m_sprite;

	Hitbox m_hitbox;
};