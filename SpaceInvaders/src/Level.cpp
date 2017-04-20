#include "../include/Level.h"

namespace space_invaders
{

level::level()
{
	ship* s = new ship();
	add_game_object((game_object*)s);
}

}
