#pragma once

#include <list>

#include "Sprite.h"
#include "GameInfo.h"

class Animation : public Component
{
public:
	explicit Animation(const float p_animationSpeed = 0.2f);
	~Animation();

	void LoadFolder(const std::string p_folderPath, const size_t p_nbElem, const std::string p_extension);

	void SetAnimationSpeed(const float p_value) { m_animationSpeed = p_value; }
	void SetLoop(const bool p_state) { m_isLoop = p_state; }

	void Update(GameInfo& p_gameInfo);

	void AddFrame(const std::string p_path);

	void NextFrame();

	bool IsEmpty() const { return m_frames.empty(); }
	bool IsEnded() const { return m_loopsDone >= 1; }
	bool IsLoop() const { return m_isLoop; }

	size_t& GetLoopsDone() { return m_loopsDone; }

	void MergeTo(const float p_x, const float p_y, const float p_scaleX = 1, const float p_scaleY = 1);
	void Reset();

	void DrawCurrentFrame();

	Sprite* GetCurrentSprite();

private:
	std::vector<Sprite*> m_frames;
	size_t m_currentFrame;
	size_t m_loopsDone;

	bool m_isLoop;

	float m_animationSpeed;
	float m_animationTimer;
};
