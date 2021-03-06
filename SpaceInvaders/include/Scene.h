#ifndef SCENE_H
#define SCENE_H

#include "RenderEngine.h"
#include "GameObject.h"
#include "Ship.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemySpawner.h"

namespace space_invaders
{

class scene
{

public:
	virtual void on_notify(game_object_event e, game_object* sender) = 0;
	void update_scene();
	void render_all(render_engine* renderer);

	uint8_t get_game_state();

protected:
	virtual void draw_gui(render_engine* renderer) = 0;//pooor style, i'm sorry

	//slotting game_objects
	const static int MAX_GAME_OBJS = 100;
	game_object* game_objs[MAX_GAME_OBJS] = {0};
	int slots[MAX_GAME_OBJS] = {0};
	int next_obj_id = 1;

	void add_game_object(game_object* go);
	void delete_game_object(int id);

	uint8_t game_state = 1; //1 means running, 0 means finished
private:
	//physics helper functions for conenience/readability
	void update_physics();
	bool is_inside(int16_t x_check, int16_t y_check,
		int16_t w, int16_t h, int16_t x_test, int16_t y_test);
};

}

#endif
