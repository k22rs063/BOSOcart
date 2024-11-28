#include "Botton.h"
Botton::Botton()
{
}

Botton::~Botton()
{
}

bool Botton::button_pressed_center()
{
    return ev3_button_is_pressed(ENTER_BUTTON);
}

bool Botton::button_pressed_right()
{
    return ev3_button_is_pressed(RIGHT_BUTTON);
}

bool Botton::button_pressed_left()
{
    return ev3_button_is_pressed(LEFT_BUTTON);
}

bool Botton::button_pressed_up()
{
    return ev3_button_is_pressed(UP_BUTTON);
}

bool Botton::button_pressed_down()
{
    return ev3_button_is_pressed(DOWN_BUTTON);
}

