#ifndef SCENE_H
#define SCENE_H

#include "RenderEngine.h"
#include "GOInstantiator.h"

namespace space_invaders
{

class game_object;


class scene
{
public:
	//void update_scene(input_engine* input);

	void render_all(render_engine* renderer);
	void add_game_object(instantiable i);
	void delete_game_object(uint8_t id);

protected:
	//keep a dynamic array of game_objects
	//TODO: performance will increase if we implement sorting every few frames
	static const int MAX_GAME_OBJS = 50;
	game_object* game_objs[MAX_GAME_OBJS];
	uint8_t slots[MAX_GAME_OBJS];
	int next_obj_id = 1;
};

}

#endif
