#ifndef POST_GAME_H
#define POST_GAME_H

#include "Scene.h"

namespace space_invaders
{

class post_game : public scene
{
public:
	post_game();
	void on_notify(game_object_event e, game_object* sender);

protected:
	void draw_gui(render_engine* renderer);

};

}

#endif
