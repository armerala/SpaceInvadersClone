#include "../include/PostGame.h"

namespace space_invaders
{

post_game::post_game(){}

void post_game::draw_gui(render_engine* renderer)
{
	renderer->render_text("GAME OVER", 350, 220);
}

void post_game::on_notify(game_object_event e, game_object* sender)
{
}

}
