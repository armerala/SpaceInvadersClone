#ifndef LEVEL_H
#define LEVEL_H

#include "Scene.h"

namespace space_invaders
{

class level : public scene
{
public:
	level();
	void on_notify(game_object_event e, game_object* sender);

private:
	int score = 0;
	int lives_left = 3;
};

}

#endif
