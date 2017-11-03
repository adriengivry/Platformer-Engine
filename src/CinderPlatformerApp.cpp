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
	void update() override;
	void draw() override;

	GameManager& GetGameManager() { return m_GameManager; }

private:
	GameManager m_GameManager;
	bool m_mode;
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
