#ifndef SCENE_H
#define SCENE_H

#include "RenderEngine.h"
#include "GameObject.h"
#include "Ship.h"
#include "Enemy.h"
#include "Bullet.h"

namespace space_invaders
{

class scene
{

public:
	virtual void on_notify(game_object_event e, game_object* sender) = 0;
	void update_scene();
	void render_all(render_engine* renderer);

protected:
	const static int MAX_GAME_OBJS = 50;
	game_object* game_objs[MAX_GAME_OBJS] = {0};
	int slots[MAX_GAME_OBJS] = {0};
	int next_obj_id = 1;

	void add_game_object(game_object* go);
	void delete_game_object(int id);
};

}

#endif
