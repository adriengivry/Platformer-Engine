#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Info.h"
#include "GameManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderPlatformerApp : public App {
  public:
	void setup() override;
	void mouseDown(MouseEvent event) override;
	void mouseUp(MouseEvent event) override;
	void keyDown(KeyEvent event) override;
	void keyUp(KeyEvent event) override;
	void update() override;
	void draw() override;

	GameManager& GetGameManager() { return m_GameManager; }

private:
	GameManager m_GameManager;
};

void CinderPlatformerApp::setup()
{
	setWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	setFullScreen(SET_FULLSCREEN);
}

void CinderPlatformerApp::mouseDown(MouseEvent event)
{
	GetGameManager().GetEventManager().GetEvent("MOUSE_LEFT_DOWN").SetState(event.isLeftDown());
	GetGameManager().GetEventManager().GetEvent("MOUSE_RIGHT_DOWN").SetState(event.isRightDown());
}

void CinderPlatformerApp::mouseUp(MouseEvent event)
{
	GetGameManager().GetEventManager().GetEvent("MOUSE_RIGHT_DOWN").SetState(false);
	GetGameManager().GetEventManager().GetEvent("MOUSE_LEFT_DOWN").SetState(false);
}

void CinderPlatformerApp::keyDown(KeyEvent event)
{
	switch (event.getChar())
	{
	case 'w':
		GetGameManager().GetEventManager().GetEvent("MOVE_UP").SetState(true);
		break;
	case 'a':
		GetGameManager().GetEventManager().GetEvent("MOVE_LEFT").SetState(true);
		break;
	case 's':
		GetGameManager().GetEventManager().GetEvent("MOVE_DOWN").SetState(true);
		break;
	case 'd':
		GetGameManager().GetEventManager().GetEvent("MOVE_RIGHT").SetState(true);
		break;
	}
}

void CinderPlatformerApp::keyUp(KeyEvent event)
{
	switch (event.getChar())
	{
	case 'w':
		GetGameManager().GetEventManager().GetEvent("MOVE_UP").SetState(false);
		break;
	case 'a':
		GetGameManager().GetEventManager().GetEvent("MOVE_LEFT").SetState(false);
		break;
	case 's':
		GetGameManager().GetEventManager().GetEvent("MOVE_DOWN").SetState(false);
		break;
	case 'd':
		GetGameManager().GetEventManager().GetEvent("MOVE_RIGHT").SetState(false);
		break;
	}
}


void CinderPlatformerApp::update()
{
	GetGameManager().GetEventManager().UpdateMousePosition(getMousePos());
	GetGameManager().GetGameInfo().m_lastTime = GetGameManager().GetGameInfo().m_thisTime;
	GetGameManager().GetGameInfo().m_thisTime = getElapsedSeconds();
	GetGameManager().GetGameInfo().m_deltaTime = GetGameManager().GetGameInfo().m_thisTime - GetGameManager().GetGameInfo().m_lastTime;
	GetGameManager().Update();
}

void CinderPlatformerApp::draw()
{
	gl::clear(Color( 0, 0, 0 ));
	GetGameManager().Display();
}

CINDER_APP(CinderPlatformerApp, RendererGl)
