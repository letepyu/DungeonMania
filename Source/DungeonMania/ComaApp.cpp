#include "ComaApp.h"
#include "SplashScene.h"
#include "Resources.h"

ComaApp::ComaApp()
{
	device = ComaDevice::GetDevice();
}


ComaApp::~ComaApp()
{
	delete window;
	delete renderer;
	device->Release();
	Resources::destroyBitmaps();
}

void ComaApp::initApp(HINSTANCE hInstance)
{
	window = new ComaWindow(hInstance);
	window->setScreenSize(1920,1080);
	window->removeStyle(WS_THICKFRAME);
	window->removeStyle(WS_MAXIMIZEBOX);
	window->setFullscreen(true, 1920, 1080);
	window->setTitle(TEXT("던전매니아 (프로토타입)"));

	renderer = new ComaRenderer();
	renderer->setBackgroundColor(0.0f, 0.0f, 0.0f);

	device->setWindowRenderer(window, renderer);
	device->initDevice();
	Resources::initBitmaps();
	device->getSceneManager()->changeScene(new SplashScene());
}
void ComaApp::run()
{
	device->run();
}