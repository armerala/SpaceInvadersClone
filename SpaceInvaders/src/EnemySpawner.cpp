#include "../include/EnemySpawner.h"

namespace space_invaders
{

int enemy_spawner::spawn_delay = 4000;

enemy_spawner::enemy_spawner() : game_object(0, 0, 0, 0, NOT_RENDERED, BLACK, SPAWNER)
{
	randomSeed(millis());
	last_spawn_time = millis();
}

void enemy_spawner::update()
{
	//spawn an enemy if the delay has been long enough
	unsigned long current_time = millis();
	unsigned long delta_time = current_time-last_spawn_time;
	if ( delta_time > spawn_delay)
	{
		notify_scene(CREATE_ENEMY);
		last_spawn_time = current_time;
	}

	//TODO: speed up the spawn rate over time
}

}
