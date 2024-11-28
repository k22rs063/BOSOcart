#ifndef RUNACTION_H
#define RUNACTION_H

#include "B_ColorSensor.h"
#include "SetMotor.h"


class RunAction{
    public:
    virtual ~RunAction();

    virtual void start() = 0;
    virtual void stop() = 0;

   static void setObject(
		B_ColorSensor *b_ColorSensor,
		SetMotor *setMotor,
        RunAction *motorControl,
        RunAction *lineTrace);

  protected:
	/* 使用するクラスのオブジェクト */
	static B_ColorSensor *mB_ColorSensor;
	static SetMotor *mSetMotor;
    static RunAction *mMotorControl;
    static RunAction *mLineTrace;
};

#endif