#ifndef GAME_H
#define GAME_H

//#include "InputManager.h"
#include "RenderEngine.h"
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
	//input_manager* input;

	//various levels we'll need
	scene* active_scene;

	//main_menu* menu;
	//level* lvl;
	//leaderboard* lb;
};

}
#endif
