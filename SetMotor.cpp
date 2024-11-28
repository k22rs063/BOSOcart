#include "SetMotor.h"

SetMotor::SetMotor(ev3api::Motor& leftWheel, ev3api::Motor& rightWheel)
: mLeftWheel(leftWheel), mRightWheel(rightWheel){
}

SetMotor::~SetMotor(){
}


void SetMotor::setSpeed(double left_power,double right_power){
    mLeftWheel.setPWM(left_power);
    mRightWheel.setPWM(right_power);
}

int SetMotor::getRinghtEncoder(){
    return mRightWheel.getCount();
}

int SetMotor::getLeftEncoder(){
    return mLeftWheel.getCount();
}