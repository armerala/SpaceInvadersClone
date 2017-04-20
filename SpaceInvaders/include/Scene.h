#ifndef SCENE_H
#define SCENE_H

#include "RenderEngine.h"
#include "GameObject.h"

namespace space_invaders
{


class scene
{
public:
	//void update_scene(input_engine* input);

	void on_notify(game_object_event e);
	void render_all(render_engine* renderer);

protected:
	const int MAX_GAME_OBJS = 50;
	game_object* game_objs[];//dangerous memory handle here, don't fuck up
	uint8_t slots[];
	int next_obj_id;

	void add_game_object(game_object* go);
	void delete_game_object(uint8_t id);
};

}

#endif
