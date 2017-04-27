#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "GameObject.h"
#include "Enemy.h"
#include <Arduino.h>

namespace space_invaders
{

class enemy_spawner : public game_object
{

public:
	enemy_spawner();

protected:
	void update();

private:
	unsigned long last_spawn_time;
	static int spawn_delay;//milliseconds

};

}

#endif
