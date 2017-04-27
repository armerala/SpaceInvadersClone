#ifndef GAME_H
#define GAME_H

#include "RenderEngine.h"
#include "InputManager.h"
#include "Scene.h"
#include "Level.h"
#include "PostGame.h"

namespace space_invaders
{
enum scene_id
{
	LEVEL,
	POST_GAME,
};

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
	scene_id current_scene_id;
	void load_level(scene_id s);

	//main_menu* menu;
	//level* lvl;
	//leaderboard* lb;
};

}
#endif
