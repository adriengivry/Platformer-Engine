#pragma once

enum GameState
{
	STATE_PLAY,
	STATE_PAUSE,
	STATE_DEFEAT
};

struct GameInfo
{
	bool m_run = true;
	uint8_t m_gameState = STATE_PLAY;

	double m_lastTime = 0;
	double m_thisTime = 0;
	double m_deltaTime = 0;
};