#include "../include/RenderEngine.h"

namespace space_invaders
{

render_engine::render_engine()
{
	//try to connect to display, otherwise freeze
	screen = new Adafruit_RA8875(RA8875_CS, RA8875_RESET);

	if (!screen->begin(RA8875_800x480))
	{
		Serial.println("RA8875 Not Found!");
		while(1);
	}

	Serial.println("RA8875 driver board found.");

	//boilerplate initialization of screen
	screen->displayOn(true);
	screen->GPIOX(true); //NOTE: general-purpose io tied to enable
	screen->PWM1config(true, RA8875_PWM_CLK_DIV1024); //PWM for backlight
	screen->PWM1out(255);

	//TODO: do I need these two lines, can't find info on them
	//seems like they might be for resistive touch, but everywhere
	//i go, I see that they're enabled anyway
	pinMode(RA8875_INT, INPUT);
	digitalWrite(RA8875_INT, HIGH);

	screen->touchEnable(false); //no touch

	Serial.println("Status : ");
	Serial.println(screen->readStatus(), HEX);
}

//wrapper to hide library functionality from game objects
//NOTE: Bitmaps are too slow on arduino for a game, primitives are best
void render_engine::render_shape(shape s, color c, int x, int y, int w, int h)
{
	//NOTE: no support for rotation/transformation
	if (screen)
	{
		switch(s)
		{
			TRIANGLE:
			{
				//calculate center/draw
				uint16_t x_0 = x - (w/2);
				uint16_t y_0 = y - (h/2);

				uint16_t x_1 = x + (w/2);
				uint16_t y_1 = y - (h/2);

				uint16_t x_2 = x;
				uint16_t y_2 = y + (h/2);

				screen->drawTriangle(x_0, y_0, x_1, y_1, x_2, y_2, c);
				screen->fillTriangle(x_0, y_0, x_1, y_1, x_2, y_2, c);
				break;
			}
			SQUARE:
			{
				screen->drawRect(x, y, w, h, c);
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void render_engine::reset_screen()
{
	if (screen)
	{
		screen->fillScreen(RA8875_BLACK);
	}
}

render_engine::~render_engine()
{
	delete screen;
}

}
