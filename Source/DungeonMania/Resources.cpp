#include "Resources.h"
#define DeleteScreen(x) if(x) delete x;
Bitmap* Resources::COMA_LOGO;
Bitmap* Resources::GAME_LOGO;
Bitmap* Resources::BLACK_SCREEN;
Bitmap* Resources::CHARACTER_SPRITE;
Bitmap* Resources::CHARACTER_DIRECTION_SPRITE;
Bitmap* Resources::TITLE_SCENE_BACKGROUND;

void Resources::initBitmaps()
{
	COMA_LOGO = Bitmap::createBitmap(L"res\\ComaLogo.png");
	GAME_LOGO = Bitmap::createBitmap(L"res\\DungeonManiaLogo.png");
	BLACK_SCREEN = Bitmap::createBitmap(L"res\\blackScreen.png");
#ifdef _DEBUG
	COMA_LOGO = Bitmap::createBitmap(L"E:\\Projects\\GitProjects\\DungeonMania\\Source\\DungeonMania\\Debug\\res\\ComaLogo.png");
	GAME_LOGO = Bitmap::createBitmap(L"E:\\Projects\\GitProjects\\DungeonMania\\Source\\DungeonMania\\Debug\\res\\DungeonManiaLogo.png");
	BLACK_SCREEN = Bitmap::createBitmap(L"E:\\Projects\\GitProjects\\DungeonMania\\Source\\DungeonMania\\Debug\\res\\blackScreen.png");
	CHARACTER_SPRITE = Bitmap::createBitmap(L"E:\\Projects\\GitProjects\\DungeonMania\\Source\\DungeonMania\\Debug\\res\\characterSprite.png");
	CHARACTER_DIRECTION_SPRITE = Bitmap::createBitmap(L"E:\\Projects\\GitProjects\\DungeonMania\\Source\\DungeonMania\\Debug\\res\\characterDirectionSprite.png");
	TITLE_SCENE_BACKGROUND = Bitmap::createBitmap(L"E:\\Projects\\GitProjects\\DungeonMania\\Source\\DungeonMania\\Debug\\res\\TitleScene\\background.png");
#endif
}
void Resources::destroyBitmaps()
{
	DeleteScreen( COMA_LOGO		);
	DeleteScreen( GAME_LOGO		);
	DeleteScreen( BLACK_SCREEN	);
}

Resources::Resources()
{
}


Resources::~Resources()
{
}
