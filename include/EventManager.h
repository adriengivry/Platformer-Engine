#pragma once

#include <map>
#include "cinder/app/App.h"

#include "Manager.h"
#include "Event.h"

class EventManager : public Manager
{
public:
	EventManager();
	~EventManager() {}

	std::map<std::string, AG::Event>& GetEvents();
	glm::vec2& GetMousePosition() { return m_mousePosition; }
	glm::vec2 GetMousePosition() const { return m_mousePosition; }

	void AddEvent(std::string p_name, const bool p_state = true);
	AG::Event& GetEvent(const std::string p_name) { return m_events[p_name]; }
	void UpdateMousePosition(const glm::vec2& p_mousePosition);
	void UpdateMousePosition(const float p_x, const float p_y);
private:
	std::map<std::string, AG::Event> m_events;
	glm::vec2 m_mousePosition;
};