#include "../include/Scene.h"

namespace space_invaders
{

/*
void scene::update_scene(input_engine* input)
{
//loop through the game objects and call update on each of them

}
*/

void scene::render_all(render_engine* renderer)
{
	//loop through the game objects and rendder them all
	for (uint16_t i = 0 ; i < MAX_GAME_OBJS; i++)
	{
		if (game_objs[i]!=NULL)
		{
			game_objs[i]->render(renderer);
		}
	}
}

void scene::on_notify(game_object_event e)
{
	switch(e)
	{
		default:
			break;
	}
}

void scene::add_game_object(game_object* go)
{
	//search for the first empty slot and delete
	uint8_t first_empty_idx = -1;
	for (uint8_t i = 0; i< MAX_GAME_OBJS; i++)
	{
		if (slots[i] != 0)
		{
			first_empty_idx = i;
			break;
		}
	}

	//create object using the next id, fill the slot, increment idx
	if (first_empty_idx != -1)
	{
		game_objs[first_empty_idx] = go;
		go->attach(this);
		slots[first_empty_idx] = next_obj_id;
		next_obj_id++;
	}

}

void scene::delete_game_object(uint8_t id)
{
	//Arduino does not support c++ std::map, so best option is a linear search
	for (int i = 0; i < MAX_GAME_OBJS; i++)
	{
		if (slots[i] == id)
		{
			delete game_objs[i];
			game_objs[i] = NULL;//TODO: do i need this? real brain fart rn
			slots[i] = 0;
		}
	}
}

}
