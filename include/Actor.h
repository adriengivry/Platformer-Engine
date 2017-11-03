#pragma once

#include "GameObject.h"

class Actor : public GameObject
{
public:
	Actor();
	~Actor() {}

	bool IsAlive() const { return m_life > 0; }
	void SetLife(const int p_value) { m_life = p_value; }
	void RemoveLife(const int p_value) { m_life -= p_value; }
	void AddLife(const int p_value) { m_life += p_value; }

protected:
	int m_life;
};