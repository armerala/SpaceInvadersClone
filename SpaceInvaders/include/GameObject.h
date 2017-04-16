#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "RenderEngine.h"

namespace space_invaders
{

class scene;//not elegent, but it works for this small project

enum game_object_event{
	CREATE_BULLET,
	CREATE_ENEMY,
};

class game_object
{
public:
	//methods called by scene
	//virtual void update(input_engine input);
	virtual void render(render_engine* renderer) = 0;

	//implement listener pattern to communicate w/ scene
	void attach(scene* sc);

	//accessors
	int get_pos_x();
	int get_pos_y();
	uint8_t get_id();

protected:
	//crude signal implementation
	void notify_scene(game_object_event e);
	scene* owner_scene;

	//position backing
	uint8_t id; //must be constructed with an id
	int pos_x;
	int pos_y;
};

}

#endif
