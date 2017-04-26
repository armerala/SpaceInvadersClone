#include "../include/Enemy.h"
#include "../include/RenderEngine.h"

namespace space_invaders
{

float enemy::speed = 10; //TODO: perhaps introduce enemy speed as a distribution rather than uniform for all enemies
int enemy::shot_delay_millis = 600;

//initilaize basic attributes
enemy::enemy(int x, int y) : game_object(x, y, 100, 100, SQUARE, BLUE, ENEMY)
{
	last_shot_time = millis();
}

//level can speed up the speed of enemies as it feels fit
void enemy::change_speed(int delta_speed, float delta_shot_delay)
{
	speed += delta_speed;
	shot_delay_millis += delta_shot_delay;
}

//update mostly ai logic
void enemy::update()
{
	//shoot as often as possible
	unsigned long shot_delay = last_shot_time - millis();
	if (shot_delay > shot_delay_millis)
	{
		//notify_scene(CREATE_BULLET);
		last_shot_time = millis();
	}

	//continually move towards the player
	pos_y += speed;
}

}
