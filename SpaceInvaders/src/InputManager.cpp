#include "../include/InputManager.h"

namespace space_invaders
{

button_state input_manager::left_button_state=NONE;
button_state input_manager::right_button_state=NONE;
button_state input_manager::shoot_button_state=NONE;

//setup hardware interrupts
void input_manager::init()
{
	pinMode(LEFT, INPUT);
	pinMode(RIGHT, INPUT);
	pinMode(SHOOT, INPUT);
	
	sei();
	attachInterrupt(LEFT, left_button_down, RISING);
	attachInterrupt(LEFT, left_button_up, FALLING);
	attachInterrupt(RIGHT, right_button_down, RISING);
	attachInterrupt(RIGHT, right_button_up, FALLING);
	attachInterrupt(SHOOT, shoot_button_down, RISING);
	attachInterrupt(SHOOT, shoot_button_up, FALLING);
}

//interrupt service routines
void input_manager::left_button_down()
{
	left_button_state = DOWN;
}

void input_manager::left_button_up()
{
	left_button_state = UP;
}

void input_manager::right_button_down()
{
	right_button_state = DOWN;
}

void input_manager::right_button_up()
{
	right_button_state = UP;
}

void input_manager::shoot_button_down()
{
	shoot_button_state = DOWN;
}

void input_manager::shoot_button_up()
{
	shoot_button_state = UP;
}

//accessor for the currently pressed buttons
button_state input_manager::get_button_state(button b)
{
	//accessor for button states
	button_state state;
	switch(b)
	{
		case LEFT:
			state = input_manager::left_button_state;
			break;
		case RIGHT:
			state = input_manager::right_button_state;
			break;
		case SHOOT:
			state = input_manager::shoot_button_state;
			break;
		default:
			state = NONE;
			break;
	}
}

}
