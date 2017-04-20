#ifndef SHIP_H
#define SHIP_H

#include "Scene.h"
#include "GameObject.h"

namespace space_invaders
{

class ship : public game_object
{
public:
	ship();
	void render(render_engine* renderer);

private:	
};

}

#endif
