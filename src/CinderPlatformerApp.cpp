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
	void mouseDown( MouseEvent event ) override;
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

void CinderPlatformerApp::mouseDown( MouseEvent event )
{
}

void CinderPlatformerApp::update()
{
	GetGameManager().Update();
}

void CinderPlatformerApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
	GetGameManager().Display();
}

CINDER_APP(CinderPlatformerApp, RendererGl)
