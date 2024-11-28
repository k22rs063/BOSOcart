#include "MotorControl.h"

MotorControl::MotorControl()
{
}

MotorControl::~MotorControl()
{
}

void MotorControl::start()
{
    mSetMotor->setSpeed(set_l_speed,set_r_speed);
}

void MotorControl::stop()
{
    mSetMotor->setSpeed(0,0);
}

void MotorControl::setParameter(double l_speed,double r_speed)
{
    set_l_speed = l_speed;
    set_r_speed = r_speed;
}