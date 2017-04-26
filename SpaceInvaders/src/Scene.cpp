#include "../include/Scene.h"

namespace space_invaders
{


void scene::update_scene()
{
	for (int i = 0; i < MAX_GAME_OBJS; i++)
	{
		//loop through the game objects and call update on each of them
		if (slots[i]!=0)
		{
			game_objs[i]->update();
		}

	}

	update_physics();
}

void scene::update_physics()
{
	//update physics now 
	//TODO: O(n^2)... I'm crying on the inside)
	//TODO: either frame-fix the game or do something, but this eats our micro-processor for breakfast
	//Perhaps a rough cull before checking might be faster? also perhaps fewer get calls if we can avoid it
	//worst part is we can't even use threading on arduino
	for (int i = 0; i< MAX_GAME_OBJS; i++)
	{
		if (slots[i] != 0)
		{
			for (int j = 0; j < MAX_GAME_OBJS; j++)
			{
				if(slots[j] != 0 && j!=i)
				{
					//grab vars needed to check if inside each other
					game_object* go_i = game_objs[i];
					game_object* go_j = game_objs[j];

					int16_t w_check = go_i->get_width();
					int16_t h_check = go_i->get_height();
					int16_t x_check = go_i->get_pos_x();
					int16_t y_check = go_i->get_pos_y();

					//get right/left x,y coords
					int16_t x_test = go_j->get_pos_x();	
					int16_t y_test = go_j->get_pos_y();	

					int16_t x_r =x_test + go_j->get_width()/2;
					int16_t x_l =x_test - go_j->get_width()/2;

					int16_t y_t = y_test - go_j->get_height()/2;
					int16_t y_b = y_test + go_j->get_height()/2;

					//perform is_inside check on all corners
					bool tl_in = is_inside(x_check, y_check, w_check, h_check, x_l, y_t);
					bool tr_in = is_inside(x_check, y_check, w_check, h_check, x_r, y_t);
					bool bl_in = is_inside(x_check, y_check, w_check, h_check, x_l, y_b);
					bool br_in = is_inside(x_check, y_check, w_check, h_check, x_r, y_b);

					if (tl_in || tr_in || bl_in || br_in)
					{
						//then collide
						//NOTE: reciprocal of this collision happens later in the loop
						go_i->on_collide(go_j);
					}
				}

			}
		}
	}
}

bool scene::is_inside(int16_t x_check, int16_t y_check, int16_t w, int16_t h, int16_t x_test, int16_t y_test)
{
	//only use square collision to check if a point is inside
	//check x first
	if ( (x_test >= x_check - w/2) && (x_test <= x_check + w/2) )
	{
		if ( (y_test >= y_check - h/2) && (y_test <= y_check + h/2) )
		{
			return true;
		}
	}

	return false;
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
