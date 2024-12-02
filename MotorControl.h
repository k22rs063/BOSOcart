#ifndef MOTERCONTROL_H
#define MOTERCONTROL_H

#include "RunAction.h"
class MotorControl :public RunAction{
    public:
    explicit MotorControl();
    virtual ~MotorControl();

    void start();
    void straight();
    void turnright();
    void trunleft();
    void Returnleft();
    void stop();
    void RotateAction(bool rotate_flag);


    void setParameter(double l_speed,double r_speed);
    private:
    double set_r_speed;
    double set_l_speed;
    int state;


};
#endif