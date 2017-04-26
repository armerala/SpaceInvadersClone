#include "../include/Ship.h"
#include "../include/RenderEngine.h"

namespace space_invaders
{

ship::ship(int x, int y) : game_object(x, y, 100, 100, TRIANGLE, GREEN, SHIP)
{
	last_shot_time = millis();
	Serial.println(x);
	Serial.println(y);
}

void ship::update()
{
	//decide if directional movement is required
	button_state l = input_manager::get_button_state(LEFT);
	button_state r = input_manager::get_button_state(RIGHT);

	//TODO: game-play-wise this is very unintuitive. Change to on_down, not down
	//so transition between left and right is easier
	if (l != r)
	{
		if (l == DOWN)
		{
			pos_x -= speed;
		}
		else if (r == DOWN)
		{
			pos_x += speed;
		}
	}

	//fire
	button_state shoot = input_manager::get_button_state(SHOOT);
	unsigned long shot_delay = last_shot_time - millis();
	if (shoot == DOWN && shot_delay > shot_delay_millis)
	{
		notify_scene(CREATE_BULLET);
		last_shot_time = millis();
	}

	if (shot_delay > shot_delay_millis)
	{
		notify_scene(CREATE_BULLET);
		last_shot_time = millis();
	}
}

void ship::on_collide(game_object* collider)
{
	//die if anything is hit
	if (collider->get_tag() == BULLET || collider->get_tag() == ENEMY)
	{
		die(); //dangeorus, but we don't get smart pointers in arduino
	}
}

}
