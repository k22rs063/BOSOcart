#ifndef SCENE_H
#define SCENE_H

#include "LineTrace.h"
#include "MotorControl.h"
#include "B_ColorSensor.h"
#include "Distance.h"
#include "Display.h"
#include "BGMControl.h"

class Scene 
{
  public:
    virtual ~Scene();

    virtual void execute() = 0; //戦術を実行する

    /* 使用するクラスのオブジェクトへの参照を設定 */
    static void setObject(
      LineTrace *lineTrace,
      MotorControl *motorControl,
      B_ColorSensor *b_ColorSensor,
      Distance *distance,
      Display *display,
      BGMControl *bgmControl);

    protected:
    /* 使用するクラスのオブジェクト */
    static LineTrace *mLineTrace;
    static MotorControl *mMotorControl;
    static B_ColorSensor *mB_ColorSensor;

    static Distance *mDistance;
    static Display *mDisplay;
    static BGMControl *mBGMControl;
    //状態
    //int state;
    int count=1;

};

#endif
