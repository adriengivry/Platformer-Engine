#include "Animation.h"

Animation::Animation(const float p_animationSpeed) : Component()
{
	m_currentFrame = 0;
	m_animationTimer = 0;
	m_animationSpeed = p_animationSpeed;
	m_loopsDone = 0;
	SetLoop(true);
}

Animation::~Animation()
{
	for(auto iterator = m_frames.begin(); iterator != m_frames.end(); ++iterator)
		delete *iterator;
}

void Animation::LoadFolder(const std::string p_folderPath, const size_t p_nbElem, const std::string p_extension)
{
	for (int i = 0; i < p_nbElem; ++i)
		AddFrame(p_folderPath + "/" + "frame_" + std::to_string(i) + "." + p_extension);
}

void Animation::Update(GameInfo& p_gameInfo)
{
	m_animationTimer += p_gameInfo.m_deltaTime;

	if (m_animationTimer >= m_animationSpeed)
	{
		m_animationTimer = 0;
		NextFrame();
	}
}

void Animation::AddFrame(const std::string p_path)
{
	m_frames.push_back(new Sprite(p_path));
}

void Animation::NextFrame()
{
	if (!IsEmpty())
	{
		if (m_currentFrame == m_frames.size() - 1)
		{
			if (IsLoop())
			{
				m_currentFrame = 0;
				++m_loopsDone;
			}
			else
			{
				m_loopsDone = 1;
			}
		}
		else
			++m_currentFrame;
	}
}

void Animation::MergeTo(const float p_x, const float p_y, const float p_scaleX, const float p_scaleY)
{
	for (auto iterator = m_frames.begin(); iterator != m_frames.end(); ++iterator)
	{
		(*iterator)->SetPosition(p_x, p_y);
		(*iterator)->SetScale(p_scaleX, p_scaleY);
	}
}

void Animation::Reset()
{
	m_currentFrame = 0;
	m_loopsDone = 0;
	m_animationTimer = 0;
}

void Animation::DrawCurrentFrame()
{
	if (!IsEmpty())
		m_frames[m_currentFrame]->Draw();
}

Sprite* Animation::GetCurrentSprite()
{
	if (IsEmpty()) 
		return nullptr;

	return m_frames[m_currentFrame];
}
