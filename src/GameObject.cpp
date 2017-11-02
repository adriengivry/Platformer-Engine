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

void GameObject::Update(EventManager& p_eventManager)
{
	if (IsUpdatable())
	{
		if (IsTickable())
			Tick();

		if (IsHoverable() && IsHovered(p_eventManager))
			OnMouseover();

		if (IsHoverable() && IsHovered(p_eventManager) && p_eventManager.GetEvent("MOUSE_LEFT_DOWN").IsOn())
		{
			OnMouseLeftclick();
			p_eventManager.GetEvent("MOUSE_LEFT_DOWN").Toggle();
		}

		if (IsHoverable() && IsHovered(p_eventManager) && p_eventManager.GetEvent("MOUSE_RIGHT_DOWN").IsOn())
		{
			OnMouseRightClick();
			p_eventManager.GetEvent("MOUSE_RIGHT_DOWN").Toggle();
		}
	}
}

void GameObject::Tick()
{
	// TODO: Actor tick
}

void GameObject::Draw()
{
	if (IsDrawable())
	{
		GetSprite().Draw();
	}
}

void GameObject::OnMouseover()
{
}

void GameObject::OnMouseLeftclick()
{
}

void GameObject::OnMouseRightClick()
{
}
