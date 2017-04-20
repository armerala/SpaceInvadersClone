#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "ModelEnums.h"

namespace space_invaders
{

class scene;

class game_object
{
public:
	//methods called by scene
	//virtual void update(input_engine input, go_instantiator* instantiator);
	void attach(scene* s);

	//accessors
	int get_pos_x();
	int get_pos_y();
	int get_width();
	int get_height();
	int get_id();
	shape get_model();
	color get_texture();

protected:
	//property backings
	int id; //TODO: must be constructed with an id
	int pos_x;
	int pos_y;
	int width;
	int height;
	shape model;
	color texture;

	//crude signaling to allow object instantiation by other objs
	scene* owner_scene;
	void spawn_object(instantiable i);
};

}

#endif
