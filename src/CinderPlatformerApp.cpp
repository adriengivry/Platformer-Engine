#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderPlatformerApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void CinderPlatformerApp::setup()
{
}

void CinderPlatformerApp::mouseDown( MouseEvent event )
{
}

void CinderPlatformerApp::update()
{
}

void CinderPlatformerApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( CinderPlatformerApp, RendererGl )
