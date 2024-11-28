#ifndef MOTERCONTROL_H
#define MOTERCONTROL_H

#include "RunAction.h"
class MotorControl :public RunAction{
    public:
    explicit MotorControl();
    virtual ~MotorControl();

    void start();
    void stop();


    void setParameter(double l_speed,double r_speed);
    private:
    double set_r_speed;
    double set_l_speed;


};
#endif