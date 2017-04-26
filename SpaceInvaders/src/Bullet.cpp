#include "../include/Bullet.h"
#include "../include/RenderEngine.h"

namespace space_invaders
{

float bullet::speed = 10; 

bullet::bullet(int x, int y, int8_t direction) : game_object(x, y, 15, 15, SQUARE, WHITE, BULLET)
{
	//direction is a normalized bullet direction (up=1 or down=-1)
	speed *= (direction/abs(direction));
}

void bullet::update()
{
	pos_y += speed;
}

void bullet::on_collide(game_object* collider)
{
	//bullet annihilates things like antimatter
	die();
}

}
