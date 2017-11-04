#pragma once

#include "Actor.h"

class FixedActor : public Actor
{
public:
	FixedActor();
	~FixedActor() {}

	void Construct(const std::string p_path, const float p_x, const float p_y, const float p_scaleX = 1, const float p_scaleY = 1);

protected:

};
