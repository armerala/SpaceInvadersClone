#ifndef GO_INSTANTIATOR_H
#define GO_INSTANTIATOR_H

#include "ModelEnums.h"
#include "Ship.h"
class scene;
class game_object;

namespace space_invaders
{

//This class provides some indirection to avoid circular dependency
//while still allowing game objects to spawn other game objects if need be
class go_instantiator
{
public:
	static game_object* create_new(instantiable i, scene* s);

};

}

#endif
