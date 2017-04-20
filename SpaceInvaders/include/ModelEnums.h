#ifndef MODEL_ENUMS_H
#define MODEL_ENUMS_H

namespace space_invaders
{

//some enums to somewhat hide direct access of library from game objects
enum instantiable
{
	SHIP,
	BULLET,
};

enum shape
{
	NONE,
	TRIANGLE,
	SQUARE,
	CIRCLE,
};

//mirror the rgb565 values of the ra8875 lib
enum color
{
	BLACK = 0x0000,
	BLUE = 0x001F,
	RED = 0xF800,
	GREEN = 0x07E0,
	CYAN = 0x07FF,
	MAGENTA = 0xF81F,
	YELLOW = 0xFFE0,
	WHITE = 0xFFFF,
};

}

#endif