#include "../include/Level.h"

namespace space_invaders
{

level::level()
{
	//these MUST be initialized in every 'scene' derivative or risk seg faulting
	game_objs[MAX_GAME_OBJS];
	slots[MAX_GAME_OBJS];
	next_obj_id = 1;
}

}
