#ifndef INPUT_MANAGER_H 
#define INPUT_MANAGER_H

#include <Arduino.h>

namespace space_invaders
{

enum button_state
{
	NONE,
	DOWN,
	UP,
};

enum button
{
	//correspond to the pins
	LEFT = 18,
	RIGHT = 19,
	SHOOT = 20,
};

class input_manager
{
public:
	//because of the nature of arduino interrupts, works better if class is purely static
	static void init();

	//arduino doesns't allow parameter/returns for interrupts
	static void left_button_up();
	static void left_button_down();
	static void right_button_up();
	static void right_button_down();
	static void shoot_button_up();
	static void shoot_button_down();

	static button_state get_button_state(button b);

	static button_state left_button_state;
	static button_state right_button_state;
	static button_state shoot_button_state;
};

}

#endif
