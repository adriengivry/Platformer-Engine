#pragma once

#include <map>

#include "Object.h"
#include "Sprite.h"
#include "Hitbox.h"
#include "EventManager.h"
#include "GameInfo.h"
#include "Animation.h"

class GameObject : public Object
{
public:
	GameObject();
	virtual ~GameObject();

	Sprite& GetSprite() { return m_sprite; }
	Hitbox& GetHitbox() { return m_hitbox; }
	Hitbox GetHitbox() const { return m_hitbox; }
	size_t& GetGameObjectId() { return m_gameObjectId; }
	static size_t& GetGameObjectCounter() { return s_gameObjectCounter; }
	static size_t& GetGameObjectTotalCounter() { return s_gameObjectMaxId; }

	bool IsUpdatable() const { return m_isUpdatable; }
	bool IsTickable() const { return m_isTickable; }
	bool IsDrawable() const { return m_isDrawable; }
	bool IsHoverable() const { return m_isHoverable; }
	bool IsClickable() const { return m_isClickable; }

	bool IsHovered() const { return m_isHovered; }
	bool IsHovered(EventManager& p_eventManager) const;

	void SetUpdatable(const bool p_state) { m_isUpdatable = p_state; }
	void SetTickable(const bool p_state) { m_isTickable = p_state; }
	void SetDrawable(const bool p_state) { m_isDrawable = p_state; }
	void SetHoverable(const bool p_state) { m_isHoverable = p_state; }
	void SetClickable(const bool p_state) { m_isClickable = p_state; }
	void SetHovered(const bool p_state) { m_isHovered = p_state; }

	void SetTexture(const std::string p_path) { GetSprite().SetTexture(p_path); }
	void SetTexture(const gl::Texture2dRef p_texture) { GetSprite().SetTexture(p_texture); }

	virtual void MergeTextureToHitbox(Sprite& p_sprite);

	virtual void Update(EventManager& p_eventManager, GameInfo& p_gameInfo);
	virtual void Tick(EventManager& p_eventManager, GameInfo& p_gameInfo);
	virtual void DrawHitbox();
	virtual void DrawSprite();
	virtual void Draw();
	virtual void OnMouseover(EventManager& p_eventManager, GameInfo& p_gameInfo);
	virtual void OnMouseLeftclick(EventManager& p_eventManager, GameInfo& p_gameInfo);
	virtual void OnMouseRightClick(EventManager& p_eventManager, GameInfo& p_gameInfo);

protected:
	static size_t s_gameObjectMaxId;
	static size_t s_gameObjectCounter;
	size_t m_gameObjectId;

	bool m_isUpdatable;
	bool m_isTickable;
	bool m_isDrawable;
	bool m_isHoverable;
	bool m_isClickable;
	bool m_isHovered;

	Sprite m_sprite;
	Hitbox m_hitbox;
};
