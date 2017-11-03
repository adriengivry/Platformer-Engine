#pragma once

#include "Manager.h"
#include "EventManager.h"
#include "GameInfo.h"
#include "GameScene.h"
#include "cinder/gl/gl.h"

#define NORMAL_FONT_PATH "fonts/arial.ttf"
#define NORMAL_FONT_SIZE 15

class UserInterface : public Manager
{
public:
	UserInterface(EventManager& p_eventManager, GameInfo& p_gameInfo, GameScene& p_gameScene);
	~UserInterface() {}

	EventManager& GetEventManager() const { return m_eventManager; }
	GameInfo& GetGameInfo() const { return m_gameInfo; }
	GameScene& GetGameScene() const { return m_gameScene; }

	void Update();
	void Draw();

private:
	cinder::Font m_gameInfoFont;
	cinder::ColorA m_gameInfoColor;

	EventManager& m_eventManager;
	GameInfo& m_gameInfo;
	GameScene& m_gameScene;
};