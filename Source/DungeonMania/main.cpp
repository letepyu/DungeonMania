#include <coma2d.h>
#include "ComaApp.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pStr, int nCmdShow)
{
	ComaApp* comaApp = new ComaApp();
	comaApp->initApp(hInstance);
	comaApp->run();
	return 0;
}