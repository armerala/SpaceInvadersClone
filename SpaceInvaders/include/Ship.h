#ifndef SHIP_H
#define SHIP_H

#include "GameObject.h"

namespace space_invaders
{

class ship:public game_object
{

public:
	ship(int x = 0, int y = 0, int w = 100, int h = 100);

private:
	const static shape model = TRIANGLE;
	const static color texture = BLUE;

};

}

#endif
