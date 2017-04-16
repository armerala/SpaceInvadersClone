#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <Adafruit_RA8875.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

namespace space_invaders
{

//some enums to somewhat hide direct access of library from game objects
enum shape
{
	NONE,
	TRIANGLE,
	SQUARE,
	CIRCLE,
};
enum color
{
	BLACK = RA8875_BLACK,
	WHITE = RA8875_WHITE,
	RED = RA8875_RED,
	BLUE = RA8875_BLUE,
	GREEN = RA8875_GREEN,
	YELLOW = RA8875_YELLOW,
	MAGENTA = RA8875_MAGENTA,
	CYAN = RA8875_CYAN,
};

class render_engine
{
public:
	render_engine();
	~render_engine();

	void render_shape(shape s, color c, int x, int y, int w, int h);
	void reset_screen();
	
private:
	//NOTE: connect SCLK to UNO Digital 13
	//NOTE: connect MISO to UNO Digitl 12
	//NOTE: connect MOSI to UNO Digital 11
	const int SD_CS = 6;
	const int RA8875_INT = 3;
	const int RA8875_CS = 10;
	const int RA8875_RESET = 9;

	const int PIXEL_BUF_SIZE = 20;

	Adafruit_RA8875* screen;

};

}

#endif
