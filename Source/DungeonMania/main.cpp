#include <coma2d.h>
#include "ComaApp.h"
#include <crtdbg.h>

#ifdef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE__)
#endif

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pStr, int nCmdShow)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 503;
#endif

	ComaApp* comaApp = new ComaApp();
	comaApp->initApp(hInstance);
	comaApp->run();
	return 0;
}