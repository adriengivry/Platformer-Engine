#include "GameObject.h"

size_t GameObject::s_gameObjectMaxId = 0;
size_t GameObject::s_gameObjectCounter = 0;

GameObject::GameObject() : Object()
{
	SetObjectType("GAME_OBJECT");
	m_gameObjectId = s_gameObjectMaxId++;
	++s_gameObjectCounter;

	SetUpdatable(true);
	SetTickable(true);
	SetDrawable(true);
	SetHoverable(true);
	SetClickable(true);
	SetHovered(false);
}

GameObject::~GameObject()
{
	--s_gameObjectCounter;
}

bool GameObject::IsHovered(EventManager& p_eventManager) const
{
	return GetHitbox().Intersect(p_eventManager.GetMousePosition());
}

void GameObject::MergeTextureToHitbox(Sprite& p_sprite)
{
	GetHitbox().GetSize().x = p_sprite.GetTexture()->getSize().x * p_sprite.GetScale().x;
	GetHitbox().GetSize().y = p_sprite.GetTexture()->getSize().y * p_sprite.GetScale().y;
	p_sprite.SetPosition(GetHitbox().GetPosition().x, GetHitbox().GetPosition().y);
}

void GameObject::Update(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
	if (IsUpdatable())
	{
		if (IsTickable())
			Tick(p_eventManager, p_gameInfo);

		if (IsHoverable() && IsHovered(p_eventManager))
			OnMouseover(p_eventManager, p_gameInfo);

		if (IsHoverable() && IsHovered(p_eventManager) && p_eventManager.GetEvent("MOUSE_LEFT_DOWN").IsOn())
		{
			OnMouseLeftclick(p_eventManager, p_gameInfo);
			p_eventManager.GetEvent("MOUSE_LEFT_DOWN").Toggle();
		}

		if (IsHoverable() && IsHovered(p_eventManager) && p_eventManager.GetEvent("MOUSE_RIGHT_DOWN").IsOn())
		{
			OnMouseRightClick(p_eventManager, p_gameInfo);
			p_eventManager.GetEvent("MOUSE_RIGHT_DOWN").Toggle();
		}

		SetHovered(IsHovered(p_eventManager));
	}
}

void GameObject::Tick(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
}

void GameObject::DrawHitbox()
{
	if (IsHovered())
		gl::color(HITBOX_COLOR_R, HITBOX_COLOR_G, HITBOX_COLOR_B, HITBOX_HOVERED_FILL_ALPHA);
	else
		gl::color(HITBOX_COLOR_R, HITBOX_COLOR_G, HITBOX_COLOR_B, HITBOX_FILL_ALPHA);

	gl::drawSolidRect(GetHitbox().GetRectf());
	gl::color(HITBOX_COLOR_R, HITBOX_COLOR_G, HITBOX_COLOR_B, HITBOX_STROKE_ALPHA);
	gl::drawStrokedRect(GetHitbox().GetRectf());
	gl::color(1, 1, 1, 1);
}

void GameObject::DrawSprite()
{
	if (!GetSprite().IsEmpty())
	{
		MergeTextureToHitbox(GetSprite());
		GetSprite().Draw();
	}
}

void GameObject::Draw()
{
	if (IsDrawable())
	{
		if (SHOW_HITBOX)
			DrawHitbox();

		DrawSprite();
	}
}

void GameObject::OnMouseover(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
}

void GameObject::OnMouseLeftclick(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
}

void GameObject::OnMouseRightClick(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
}

