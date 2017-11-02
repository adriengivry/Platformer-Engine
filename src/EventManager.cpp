#include "EventManager.h"

EventManager::EventManager()
{
	AddEvent("MOUSE_LEFT_DOWN", false);
}

std::map<std::string, AG::Event>& EventManager::GetEvents()
{
	return m_events;
}

void EventManager::AddEvent(std::string p_name, const bool p_state)
{
	GetEvents().insert(std::pair<std::string, AG::Event>(p_name, AG::Event(p_state)));
}

void EventManager::UpdateMousePosition(const glm::vec2& p_mousePosition)
{
	UpdateMousePosition(p_mousePosition.x, p_mousePosition.y);
}

void EventManager::UpdateMousePosition(const float p_x, const float p_y)
{
	m_mousePosition.x = p_x;
	m_mousePosition.y = p_y;
}
