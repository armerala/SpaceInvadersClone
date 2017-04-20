#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <Adafruit_RA8875.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include "ModelEnums.h"

namespace space_invaders
{

class game_object;

class render_engine
{
public:
	render_engine();
	~render_engine();

	void render_game_object(game_object* go);
	void reset_screen();
	
private:
	//NOTE: connect SCK to MEGA Digital 52
	//NOTE: connect MISO to MEGA Digitl 50
	//NOTE: connect MOSI to MEGA Digital 51
	const uint8_t RA8875_INT = 22;
	const uint8_t SD_CS = 6;
	const uint8_t RA8875_RESET = 45;
	const uint8_t RA8875_CS = 46;

	const int PIXEL_BUF_SIZE = 20;

	Adafruit_RA8875* screen;

};

}

#endif
