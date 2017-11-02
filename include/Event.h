#pragma once

#include "Component.h"

namespace AG
{
	class Event : public Component
	{
	public:
		explicit Event(const bool p_initState = false) { m_state = p_initState; }
		~Event() {}

		bool IsOn() const { return m_state; }
		bool IsOff() const { return !m_state; }

		bool GetState() const { return m_state; }

		void SetState(const bool p_state) { m_state = p_state; }
		void Toggle() { m_state = !m_state; }

	private:
		bool m_state;
	};
}