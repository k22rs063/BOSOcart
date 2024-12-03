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

void MotorControl::straight()
{
    mSetMotor->setSpeed(10,10);
}

void MotorControl::turnright()
{
    //mSetMotor->setSpeed(12,0);
    mSetMotor->setSpeed(20,-5);
}

void MotorControl::trunleft()
{
    mSetMotor->setSpeed(-5,20);
}

void MotorControl::Returnleft()
{
    mSetMotor->setSpeed(20,0);
}

void MotorControl::RotateAction(bool rotate_flag){
    if(rotate_flag){
        mSetMotor->setSpeed(set_l_speed,-set_r_speed-1);
    }else{
        mSetMotor->setSpeed(-set_l_speed,set_r_speed+1);
    }
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