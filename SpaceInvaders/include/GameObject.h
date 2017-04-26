#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "RenderEngine.h"
#include "InputManager.h"

namespace space_invaders
{

class scene;

enum game_object_tag{
	ENEMY,
	SHIP,
	BULLET,
};

enum game_object_event{
	CREATE_BULLET,
	CREATE_ENEMY,
	OBJECT_DEATH,
	POINTS_SCORED,
};

class game_object
{
public:
	//methods called by scene
	void render(render_engine* renderer);
	virtual void on_collide(game_object* collider); 
	virtual void update() = 0;

	//implement crude listener pattern w/ scene
	void attach(scene* sc, uint16_t id_num);
	void die();

	//accessors
	int get_pos_x();
	int get_pos_y();
	int get_width();
	int get_height();
	uint16_t get_id();
	game_object_tag get_tag();
	shape get_model();
	color get_texture();

protected:
	game_object(int x, int y, int w, int h, shape s, color c, game_object_tag t);

	//crude signal implementation
	void notify_scene(game_object_event e);
	scene* owner_scene;

	//various properties of objects
	int pos_x;
	int pos_y;
	const int width;
	const int height;
	const shape model;
	const color texture;
	float speed;
	game_object_tag tag;
	uint16_t id; //must be constructed with an id
};

}

#endif
