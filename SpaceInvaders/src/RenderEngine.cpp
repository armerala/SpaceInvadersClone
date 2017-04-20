#include "../include/RenderEngine.h"
#include "../include/GameObject.h"

namespace space_invaders
{

render_engine::render_engine()
{
	//try to connect to display, otherwise freeze
	screen = new Adafruit_RA8875(RA8875_CS, RA8875_RESET);

	if (!screen->begin(RA8875_800x480))
	{
		Serial.println("RA8875 Not Found!");
		while(1){
			delay(500);
		}
	}

	Serial.println("RA8875 driver board found.");

	//boilerplate initialization of screen
	screen->displayOn(true);
	screen->GPIOX(true); //NOTE: general-purpose io tied to enable
	screen->PWM1config(true, RA8875_PWM_CLK_DIV1024); //PWM for backlight
	screen->PWM1out(255);

	screen->fillScreen(RA8875_RED);

	//TODO: do I need these two lines, can't find info on them
	//seems like they might be for resistive touch, but everywhere
	//i go, I see that they're enabled anyway.
	pinMode(RA8875_INT, INPUT);
	digitalWrite(RA8875_INT, HIGH);

	screen->touchEnable(false); //no touch

	Serial.print("Status : ");
	Serial.println(screen->readStatus(), HEX);

	reset_screen();
}

//wrapper to hide library functionality from game objects
//NOTE: Bitmaps are too slow on arduino for a game, primitives are best
void render_engine::render_game_object(game_object* go)
{
	//NOTE: no support for rotation/transformation
	if (screen)
	{
		shape s = go->get_model();
		color c = go->get_texture();
		int x = go->get_pos_x();
		int y = go->get_pos_y();
		int w = go->get_width();
		int h = go->get_height();
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
		screen->fillScreen(RA8875_RED);
	}
}

render_engine::~render_engine()
{
	delete screen;
}

}
