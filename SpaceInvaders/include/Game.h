#ifndef GAME_H
#define GAME_H

#include "RenderEngine.h"
#include "InputManager.h"
#include "Scene.h"
#include "Level.h"

namespace space_invaders
{

class game{

public:
	game();
	~game();

	void update();

private:
	//framework functionality
	render_engine* renderer;

	//various levels we'll need
	scene* active_scene;

	//main_menu* menu;
	//level* lvl;
	//leaderboard* lb;
};

}
#endif
