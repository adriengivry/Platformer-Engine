#include "Actor.h"

Actor::Actor() : Object()
{
	SetUpdatable(true);
	SetTickable(true);
	SetDrawable(true);
	SetHoverable(true);
	SetClickable(true);
}

Actor::~Actor()
{
}

bool Actor::IsHovered(EventManager& p_eventManager) const
{
	return GetHitbox().Intersect(p_eventManager.GetMousePosition());
}

void Actor::Update(EventManager& p_eventManager)
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

void Actor::Tick()
{
	// TODO: Actor tick
}

void Actor::Draw()
{
	if (IsDrawable())
	{
		GetSprite().Draw();
	}
}

void Actor::OnMouseover()
{
}

void Actor::OnMouseLeftclick()
{
}

void Actor::OnMouseRightClick()
{
}
