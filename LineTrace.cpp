#include "LineTrace.h"

LineTrace::LineTrace()
{
}

LineTrace::~LineTrace()
{ 
}

void LineTrace::start()
{
    brightness = mB_ColorSensor->get_rgb();
    changeSpeed = speed;
    changeKp = kp;
    changeKi = ki;
    changeKd = kd;
    target = 30;

    deviation = target - brightness;
	integral = deviation + integral * 0.5;
	turn = changeKp * deviation + changeKi * integral + changeKd * (deviation - prev_deviation);
	prev = prev_deviation;
	prev_deviation = deviation;


    mSetMotor->setSpeed(changeSpeed + turn, changeSpeed - turn);
}

void LineTrace::stop()
{

}


void LineTrace::setParameter(double setspeed,double setkp,double setki,double setkd)
{
    speed = setspeed;
    kp = setkp;
    ki = setki;
    kd = setkd;
}