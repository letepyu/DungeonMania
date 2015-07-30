#pragma once
#include <coma2d.h>
using namespace coma2d;

class Resources
{
public:
	Resources();
	virtual ~Resources();

	static void initBitmaps();
	static void destroyBitmaps();

	static Bitmap* COMA_LOGO;
	static Bitmap* GAME_LOGO;
	static Bitmap* BLACK_SCREEN;

	static Bitmap* CHARACTER_SPRITE;
	static Bitmap* CHARACTER_DIRECTION_SPRITE;

	static Bitmap* TITLE_SCENE_BACKGROUND;
};

