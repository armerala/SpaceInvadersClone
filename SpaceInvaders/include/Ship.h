#ifndef SHIP_H
#define SHIP_H

#include "GameObject.h"

namespace space_invaders
{

class render_engine;

class ship : public game_object
{
public:
	ship(int x=300, int y=400);
	void update();
	void on_collide(game_object* collider);

private:	
	unsigned long last_shot_time;
	const int shot_delay_millis = 350;
protected:
	const float speed = 10;
};

}

#endif
