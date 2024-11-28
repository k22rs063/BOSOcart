#ifndef SET_MOTOR_H
#define SET_MOTOR_H


#include "ev3api.h"
#include "Motor.h"

class SetMotor{

    public:
    explicit SetMotor(ev3api::Motor& leftWheel, ev3api::Motor& rightWheel);
    virtual ~SetMotor();
    void setSpeed(double left_power,double right_power);
    int getRinghtEncoder();
    int getLeftEncoder();

    private:
    ev3api::Motor& mLeftWheel;
	ev3api::Motor& mRightWheel;
};

#endif