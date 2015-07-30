#pragma once
#include <coma2d.h>
#include "Resources.h"

using namespace coma2d;

class SplashScene :
	public Scene
{
public:
	SplashScene();
	virtual ~SplashScene();

private:
	void loadScene(Event* event);
	void loadComplete(Event* event);
	void updateListener(Event* event);

	Image* comaLogo;
	int animationStep;
	float timeCount;
};

