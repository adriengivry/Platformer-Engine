#include "GameObject.h"

GameObject::GameObject() : Object()
{
	SetUpdatable(true);
	SetTickable(true);
	SetDrawable(true);
	SetHoverable(true);
	SetClickable(true);
}

bool GameObject::IsHovered(EventManager& p_eventManager) const
{
	return GetHitbox().Intersect(p_eventManager.GetMousePosition());
}

void GameObject::MergeTextureToHitbox()
{
	GetHitbox().GetSize().x = GetSprite().GetTexture()->getSize().x * GetSprite().GetScale().x;
	GetHitbox().GetSize().y = GetSprite().GetTexture()->getSize().y * GetSprite().GetScale().y;
	GetSprite().SetPosition(GetHitbox().GetPosition().x, GetHitbox().GetPosition().y);
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
	}
}

void GameObject::Tick(EventManager& p_eventManager, GameInfo& p_gameInfo)
{
}

void GameObject::DrawHitbox()
{
	if (SHOW_HITBOX)
	{
		gl::color(HITBOX_COLOR_R, HITBOX_COLOR_G, HITBOX_COLOR_B, HITBOX_FILL_ALPHA);
		gl::drawSolidRect(GetHitbox().GetRectf());
		gl::color(HITBOX_COLOR_R, HITBOX_COLOR_G, HITBOX_COLOR_B, HITBOX_STROKE_ALPHA);
		gl::drawStrokedRect(GetHitbox().GetRectf());
		gl::color(1, 1, 1, 1);
	}
}

void GameObject::Draw()
{
	if (IsDrawable())
	{
		DrawHitbox();
		MergeTextureToHitbox();
		GetSprite().Draw();
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

