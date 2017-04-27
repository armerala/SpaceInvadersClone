#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

namespace space_invaders
{

class render_engine;
enum shape;
enum color;

class enemy : public game_object
{

public:
	enemy(int x, int y = 50);
	void render(render_engine* renderer);
	void update();
	void change_speed(int delta_speed, float delta_shot_delay);

private:
	unsigned long last_shot_time;
	static int shot_delay;

protected:
	static float speed;
	void on_collide(game_object* collider);

};

}

#endif
