#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

namespace space_invaders
{

class render_engine;

class bullet : public game_object
{
public:
	bullet(int x, int y, int8_t direction);
	void update();
	void on_collide(game_object* collider) override ;

protected:

private:
	static float speed;

};

}

#endif
