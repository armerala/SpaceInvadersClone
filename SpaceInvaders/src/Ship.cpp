#include "../include/Ship.h"

namespace space_invaders
{

ship::ship()
{
}

void ship::render(render_engine* renderer)
{
	renderer->render_shape(model, texture, pos_x, pos_y, width, height);
}

}
