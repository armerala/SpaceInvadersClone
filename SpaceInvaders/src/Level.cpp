#include "../include/Level.h"

namespace space_invaders
{

level::level()
{
	add_game_object((game_object*) new ship(60));
	add_game_object((game_object*) new enemy (20));
}


void level::on_notify(game_object_event e, game_object* sender)
{
	game_object_tag t = sender->get_tag();
	int id = sender->get_id();
	switch(e)
	{
		case CREATE_BULLET:
			break;
		case CREATE_ENEMY:
			break;
		case OBJECT_DEATH:
			if (t == SHIP)
			{
				lives_left--;
			}
			delete_game_object(id);
			break;
		case POINTS_SCORED:
			break;
		default:
			break;
	}
}

}
