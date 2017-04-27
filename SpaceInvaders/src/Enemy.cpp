#include "../include/Enemy.h"
#include "../include/RenderEngine.h"

namespace space_invaders
{

float enemy::speed = 2; //TODO: perhaps introduce enemy speed as a distribution rather than uniform for all enemies
int enemy::shot_delay = 2000;

//initilaize basic attributes
enemy::enemy(int x, int y) : game_object(x, y, 80, 80, SQUARE, BLUE, ENEMY)
{
	last_shot_time = millis();
}

//level can speed up the speed of enemies as it feels fit
void enemy::change_speed(int delta_speed, float delta_shot_delay)
{
	speed += delta_speed;
	shot_delay += delta_shot_delay;
}

//update mostly ai logic
void enemy::update()
{
	//shoot as often as possible
	unsigned long current_time = millis();
	unsigned long delta_time = current_time - last_shot_time; 
	if (delta_time > shot_delay)
	{
		notify_scene(CREATE_BULLET);
		last_shot_time = millis();
	}

	//continually move towards the player
	pos_y += speed;

	//if below/near edge of screen, just kill self and lose points
	if (pos_y >= 430)
	{
		notify_scene(POINTS_LOST);
		die();
	}
}

void enemy::on_collide(game_object* collider)
{
	game_object_tag t = collider->get_tag();
	if (t == SHIP || t == BULLET)
	{
		die();
	}
}

}
