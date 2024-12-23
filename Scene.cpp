#include "Scene.h"

LineTrace *Scene::mLineTrace;
MotorControl *Scene::mMotorControl;
B_ColorSensor *Scene::mB_ColorSensor;
Distance *Scene::mDistance;
Display *Scene::mDisplay;
BGMControl *Scene::mBGMControl;

// デストラクタ
Scene::~Scene() {
}

// static メンバ関数の定義
void Scene::setObject(
    LineTrace *lineTrace,
    MotorControl *motorControl,
    B_ColorSensor *b_ColorSensor,
    Distance *distance,
    Display *display,
    BGMControl *bgmControl) 
{
    mLineTrace = lineTrace;
    mMotorControl = motorControl;
    mB_ColorSensor = b_ColorSensor;
    mDistance = distance;
    mDisplay = display;
    mBGMControl = bgmControl;
}

