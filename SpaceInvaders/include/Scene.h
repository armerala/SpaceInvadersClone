#ifndef SCENE_H
#define SCENE_H

#include "RenderEngine.h"
#include "GameObject.h"
#include "Ship.h"

namespace space_invaders
{


class scene
{
public:
	//void update_scene(input_manager* input);

	void on_notify(game_object_event e);
	void render_all(render_engine* renderer);

protected:
	const static int MAX_GAME_OBJS = 50;
	game_object* game_objs[MAX_GAME_OBJS];
	uint8_t slots[MAX_GAME_OBJS];
	int next_obj_id = 1;

	void add_game_object(game_object* go);
	void delete_game_object(uint8_t id);
};

}

#endif
