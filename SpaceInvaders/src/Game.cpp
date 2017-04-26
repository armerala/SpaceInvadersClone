#include "../include/Game.h"

namespace space_invaders
{

game::game()
{
	//menu = new main_menu();
	//lvl = new level();
	//lb = new leaderboard();

	level* l = new level();
	active_scene =  (scene*) l;

	renderer = new render_engine();
	input_manager::init();
}

void game::update()
{
	if (active_scene)
	{
		active_scene->update_scene();
		active_scene->render_all(renderer);	
	}
}

game::~game()
{
	//delete menu;
	//delete lvl;
	//delete lb;
	
	delete renderer;
	//delete input;
}

}
