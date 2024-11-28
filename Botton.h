#ifndef BOTTON_SENSOR_H
#define BOTTON_SENSOR_H

#include "ev3api.h"

class Botton
{
    public:
    explicit Botton();
    virtual ~Botton();
    bool button_pressed_center();
    bool button_pressed_right();
    bool button_pressed_left();
    bool button_pressed_up();
    bool button_pressed_down();

    private:
    
};
#endif