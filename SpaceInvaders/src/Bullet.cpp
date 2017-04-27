#include "../include/Bullet.h"
#include "../include/RenderEngine.h"

namespace space_invaders
{

float bullet::speed = 12; 

bullet::bullet(int x, int y, int8_t direction) : game_object(x, y, 15, 15, SQUARE, WHITE, BULLET)
{
	//direction is a normalized bullet direction (up=-1 or down=1)
	speed *= (direction/abs(direction));
}

void bullet::update()
{
	pos_y += speed;

	//don't let if go off the screen();
	if (pos_y >= 450 || pos_y <=30)
	{
		die();
	}
}

void bullet::on_collide(game_object* collider)
{
	//bullet annihilates things like antimatter
	die();
}

}
