#include "../include/Game.h"

namespace space_invaders
{

game::game()
{
	//menu = new main_menu();
	//lvl = new level();
	//lb = new leaderboard();

	renderer = new render_engine();
	input_manager::init();

	load_level(LEVEL);
}

void game::update()
{
	if (active_scene)
	{
		active_scene->update_scene();
		active_scene->render_all(renderer);	
		if (active_scene->get_game_state() == 0)
		{
			if (current_scene_id == LEVEL)
			{
				load_level(POST_GAME);
			}
			else
			{
				load_level(LEVEL);
			}
		}
	}
}

void game::load_level(scene_id s)
{
	switch(s)
	{
		case LEVEL:
			active_scene = (scene*) new level();
			current_scene_id=LEVEL;
			break;
		case POST_GAME:
			current_scene_id=POST_GAME;
			active_scene = (scene*) new post_game();
			break;
		default:
			break;
	}
}

game::~game()
{
	//delete menu;
	//delete lvl;
	//delete lb;
	
	delete renderer;
	delete active_scene;
	//delete input;
}

}
