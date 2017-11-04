#include "FixedActor.h"

FixedActor::FixedActor() : Actor()
{
	SetObjectType("FIXED_ACTOR");

	SetUpdatable(false);
}

void FixedActor::Construct(const std::string p_path, const float p_x, const float p_y, const float p_scaleX, const float p_scaleY)
{
	GetSprite().SetTexture(p_path);
	GetSprite().SetScale(p_scaleX, p_scaleY);
	GetHitbox().SetPosition(p_x, p_y);
}