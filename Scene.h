#ifndef SCENE_H
#define SCENE_H

#include "LineTrace.h"
#include "MotorControl.h"
#include "B_ColorSensor.h"
#include "Distance.h"
#include "Display.h"

class Scene 
{
public:
    virtual ~Scene();
    virtual void exectue() = 0;
    //virtual bool isFinished() = 0;

    static void setObject(
        LineTrace *lineTrace,
        MotorControl *motorControl,
        B_ColorSensor* b_ColorSensor,
        Distance* distance,
        Display* display);

protected:
    // 使用するクラスのオブジェクト
    static LineTrace *mLineTrace;
    static MotorControl *mMotorControl;
    static B_ColorSensor *mB_ColorSensor;
    static Distance *mDistance;
    static Display *mDisplay;

    
    // 状態
    int state;
};

#endif
