#pragma once
#include <coma2d.h>
using namespace coma2d;
class ComaApp
{
public:
	ComaApp();
	virtual ~ComaApp();

	void initApp(HINSTANCE hInstance);
	void run();

private:
	ComaWindow* window;
	ComaRenderer* renderer;
	ComaDevice* device;
};

