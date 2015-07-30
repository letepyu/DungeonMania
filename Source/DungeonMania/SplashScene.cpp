#include "SplashScene.h"
#include "TitleScene.h"

#define SPLASH_TIME 5.0f

SplashScene::SplashScene()
	:animationStep(0)
{
	setEventListener(SceneEvent::CHANGED, BIND(SplashScene::loadScene), this);
	setEventListener(ObjectEvent::UPDATE, BIND(SplashScene::updateListener), this);
}


SplashScene::~SplashScene()
{
	delete Resources::COMA_LOGO;
	delete comaLogo;
}


void SplashScene::loadScene(Event* event)
{
	ResourceManager* resourceManager = ComaDevice::GetDevice()->getResourceManager();
	resourceManager->clear();
	resourceManager->setEventListener(ResourceManagerEvent::LOAD_COMPLETE, BIND(SplashScene::loadComplete), this);
	resourceManager->push(Resources::COMA_LOGO)
		->push(Resources::BLACK_SCREEN)
		->push(Resources::TITLE_SCENE_BACKGROUND)
		->push(Resources::CHARACTER_DIRECTION_SPRITE)
		->push(Resources::CHARACTER_SPRITE)
		->push(Resources::GAME_LOGO);
	resourceManager->loadResources();
}

void SplashScene::loadComplete(Event* event)
{
	comaLogo = new Image(Resources::COMA_LOGO);
	RECT screenSize = ComaDevice::GetDevice()->getWindow()->getScreenSize();
	comaLogo->setPosition(screenSize.right / 2 - comaLogo->getWidth() / 2, screenSize.bottom / 2 - comaLogo->getHeight() / 2);
	comaLogo->setAlpha(0.0f);
	addChild(comaLogo);
	animationStep = 1;
}

void SplashScene::updateListener(Event* event)
{
	ObjectEvent* oEvent = (ObjectEvent*)event;
	switch (animationStep)
	{
	case 0:
		break;
	case 1:
		timeCount += oEvent->deltaTime();
		if (timeCount >= 2.0f)
		{
			timeCount = 0;
			animationStep++;
		}
		break;
	case 2:
		comaLogo->setAlpha(comaLogo->getAlpha() + oEvent->deltaTime()/1.5f);
		if (comaLogo->getAlpha() >= 1.0f)
			animationStep++;
		break;
	case 3:
		timeCount += oEvent->deltaTime();
		if (timeCount >= SPLASH_TIME)
		{
			timeCount = 0;
			animationStep++;
		}
		break;
	case 4:
		comaLogo->setAlpha(comaLogo->getAlpha() - oEvent->deltaTime()/1.5f);
		if (comaLogo->getAlpha() <= 0.0f)
			animationStep++;
		break;
	case 5:
		timeCount += oEvent->deltaTime();
		if (timeCount >= 2.0f)
		{
			timeCount = 0;
			animationStep++;
		}
		break;
	case 6:
		ComaDevice::GetDevice()->getSceneManager()->changeScene(new TitleScene());
		delete this;
		break;
	}
}