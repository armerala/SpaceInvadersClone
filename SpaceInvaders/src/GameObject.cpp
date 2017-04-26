#include "../include/GameObject.h"
#include "../include/Scene.h"

namespace space_invaders
{

game_object::game_object(int x, int y, int w,int h,shape s, color c, game_object_tag t): 
	pos_x(x), pos_y(y), width(w), height(h), model(s), texture(c), tag(t)
{
}

void game_object::attach(scene* sc, uint16_t id_num)
{	
	owner_scene = sc;
	id = id_num;
}

void game_object::notify_scene(game_object_event e)
{
	if (owner_scene)
	{
		owner_scene->on_notify(e, this);
	}
}

void game_object::render(render_engine* renderer)
{
	renderer->render_shape(model, texture, pos_x, pos_y, width, height);
}

//make it optional to override this
//poor practice, but i'm on a deadline here
void game_object::on_collide(game_object* collider)
{

}

//kills self
void game_object::die()
{
	notify_scene(OBJECT_DEATH);
}

//public accessors
int game_object::get_pos_x()
{
	return pos_x;
}

int game_object::get_pos_y()
{
	return pos_y;
}

uint16_t game_object::get_id()
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

game_object_tag game_object::get_tag()
{
	return tag;
}

}
