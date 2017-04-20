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
	//loop through the game objects and render them all
	for (uint16_t i = 0 ; i < MAX_GAME_OBJS; i++)
	{
		if (game_objs[i] != NULL)
		{
			renderer->render_game_object(game_objs[i]);
		}
	}
}

//perhaps add a bool to indicate success?
void scene::add_game_object(instantiable i)
{
	//search for the first empty slot
	uint8_t first_empty_idx = -1;
	for (uint8_t i = 0; i< MAX_GAME_OBJS; i++)
	{
		if (slots[i] != 0)
		{
			first_empty_idx = i;
			break;
		}
	}

	//try to create object using the next id, fill the slot, increment idx
	if (first_empty_idx != -1)
	{
		game_object* go = go_instantiator::create_new(i, this);
		if(go)
		{
			game_objs[first_empty_idx] = go;
			slots[first_empty_idx] = next_obj_id;
			next_obj_id++;
		}
	}

}

void scene::delete_game_object(uint8_t id)
{
	//Arduino does not support c++ std::map, so best option is a linear search (until we implement object sorting by id)
	for (int i = 0; i < MAX_GAME_OBJS; i++)
	{
		if (slots[i] == id)
		{
			delete game_objs[i];
			game_objs[i] = 0; //protect against double delete
			slots[i] = 0;
		}
	}
}

}
