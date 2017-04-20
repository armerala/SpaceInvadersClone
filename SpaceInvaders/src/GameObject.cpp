#include "../include/GameObject.h"
#include "../include/Scene.h"

namespace space_invaders
{

void game_object::attach(scene* s)
{
	owner_scene = s;	
}

void game_object::spawn_object(instantiable i)
{
	//go_instantiator::create_new(i, owner_scene);
	owner_scene->add_game_object(i);
}

int game_object::get_pos_x()
{
	return pos_x;
}

int game_object::get_pos_y()
{
	return pos_y;
}

int game_object::get_id()
{
	return id;
}

int game_object::get_width()
{
	return width;
}

int game_object::get_height()
{
	return height;
}

shape game_object::get_model()
{
	return model;
}

color game_object::get_texture()
{
	return texture;
}

}
