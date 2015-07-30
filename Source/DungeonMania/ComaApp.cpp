#include "ComaApp.h"


ComaApp::ComaApp()
{
	device = ComaDevice::GetDevice();
}


ComaApp::~ComaApp()
{
	delete window;
	delete renderer;
	device->Release();
}

void ComaApp::initApp(HINSTANCE hInstance)
{
	window = new ComaWindow(hInstance);
	window->setScreenSize(1920,1080);
	window->setFullscreen(true, 1920, 1080);
	//window->removeStyle(WS_THICKFRAME);
	//window->removeStyle(WS_MAXIMIZEBOX);
	window->setTitle(TEXT("던전매니아 (프로토타입)"));

	renderer = new ComaRenderer();
	renderer->setBackgroundColor(0.0f, 0.0f, 0.1f);

	device->setWindowRenderer(window, renderer);
	device->initDevice();
}
void ComaApp::run()
{
	device->run();
}