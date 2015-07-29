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
	window->setScreenSize(1280, 720);
	//window->setFullscreen(true);
	window->removeStyle(WS_THICKFRAME);
	window->removeStyle(WS_MAXIMIZEBOX);
	window->setTitle(TEXT("던전매니아"));

	renderer = new ComaRenderer();
	renderer->setBackgroundColor(0.0f, 0.0f, 0.1f);

	device->setWindowRenderer(window, renderer);
	device->initDevice();
}
void ComaApp::run()
{
	device->run();
}