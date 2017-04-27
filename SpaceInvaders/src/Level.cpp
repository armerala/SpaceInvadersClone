#include "../include/Level.h"

namespace space_invaders
{

level::level()
{
	add_game_object((game_object*) new ship(60));
	add_game_object((game_object*) new enemy_spawner());
}


void level::on_notify(game_object_event e, game_object* sender)
{
	game_object_tag t = sender->get_tag();
	int id = sender->get_id();
	switch(e)
	{
		case CREATE_BULLET:
		{
			int8_t direction;
			int16_t bullet_y = sender->get_pos_y();
			int16_t bullet_x = sender->get_pos_x();
			
			//bullets are spawned in different relative locations
			if (t == SHIP)
			{
				direction = -1;
				bullet_y-= sender->get_height()*2/3;
				add_game_object((game_object*) new bullet(bullet_x, bullet_y, direction));
			}
			else if(t == ENEMY)
			{
				direction = 1;
				bullet_y += sender->get_height()*2/3;
				add_game_object((game_object*) new bullet(bullet_x, bullet_y, direction));

			}
			break;
		}
		case CREATE_ENEMY:
		{
			//randomize location on x and spawn it in
			//NOTE: spawn not over full screen width to avoid edge-clipping
			int16_t x = random(600);
			add_game_object((game_object*)new enemy(x+51));
			
			break;
		}
		case OBJECT_DEATH:
		{
			delete_game_object(id);
			if (t == SHIP)
			{
				//respawn if possible otherwise, game over
				lives_left--;
				if (lives_left > 0)
				{
					add_game_object((game_object*) new ship());
				}
				else
				{
					game_state = 0;
				}
			}
			break;
		}
		case POINTS_SCORED:
		{
			score+=15;
			break;
		}
		case POINTS_LOST:
		{
			score -= 3;
			break;
		}
		default:
			break;
	}
}

void level::draw_gui(render_engine* renderer)
{
	String score_str = "Score: ";
	score_str += score;
	String lives_left_str = "Lives Left: "; 
	lives_left_str += lives_left;

	renderer->render_text(score_str, 0, 5);
	renderer->render_text(lives_left_str, 650, 5);
}

}
