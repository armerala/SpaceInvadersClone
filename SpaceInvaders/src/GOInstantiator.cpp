#include "../include/GOInstantiator.h"


namespace space_invaders
{

//wrapper method to instantiate stuff, and avoid circular dependencies
game_object* go_instantiator::create_new(instantiable i, scene* s)
{
	game_object* go;
	switch(i)
	{
		case SHIP:
			go = new ship();
			break;
		default:
			//return null pointer on fail
			break;

	}
	if (go)
	{
		go->attach(s);
		return go;
	}
	else
	{
		return 0;
	}
}

}
