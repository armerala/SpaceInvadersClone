#include "../include/GameObject.h"
#include "../include/Scene.h"

namespace space_invaders
{

void game_object::attach(scene* sc)
{	
	owner_scene = sc;
}

void game_object::notify_scene(game_object_event e)
{
	if (owner_scene != NULL)
	{
		owner_scene->on_notify(e);
	}
}

int game_object::get_pos_x()
{
	return pos_x;
}

int game_object::get_pos_y()
{
	return pos_y;
}

uint8_t game_object::get_id()
{
	return id;
}

}
