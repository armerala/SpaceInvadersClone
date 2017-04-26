#include "../include/Scene.h"

namespace space_invaders
{


void scene::update_scene()
{
//loop through the game objects and call update on each of them
for (int i = 0; i < MAX_GAME_OBJS; i++)
{
	if (slots[i]!=0)
	{
		game_objs[i]->update();
	}
}
}


void scene::render_all(render_engine* renderer)
{
	//loop through the game objects and rendder them all
	renderer->reset_screen();
	for (int i = 0 ; i < MAX_GAME_OBJS; i++)
	{
		if (slots[i] != 0)
		{
			game_objs[i]->render(renderer);
		}
	}
	delay(60);
}

void scene::add_game_object(game_object* go)
{
	//search for the first empty slot and delete
	int first_empty_idx = -1;
	for (int i = 0; i< MAX_GAME_OBJS; i++)
	{
		if (slots[i] == 0)
		{
			first_empty_idx = i;
			break;
		}
	}

	//create object using the next id, fill the slot, increment idx
	if (first_empty_idx != -1)
	{
		game_objs[first_empty_idx] = go;
		go->attach(this, next_obj_id); 
		slots[first_empty_idx] = next_obj_id;
		next_obj_id++;
	}

}

void scene::delete_game_object(int id)
{
	//Arduino does not support c++ std::map, so best option is a linear search
	for (int i = 0; i < MAX_GAME_OBJS; i++)
	{
		if (slots[i] == id)
		{
			delete game_objs[i];
			game_objs[i] = 0;
			slots[i] = 0;
		}
	}
}

}
