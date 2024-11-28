#include "RunAction.h"

B_ColorSensor *RunAction::mB_ColorSensor;
SetMotor *RunAction::mSetMotor;
RunAction *RunAction::mMotorControl;
RunAction *RunAction::mLineTrace;

RunAction::~RunAction()
{
}

void RunAction::setObject(
    B_ColorSensor *b_ColorSensor,
    SetMotor *setMotor,
    RunAction *motorControl,
    RunAction *lineTrace)
{
    mB_ColorSensor = b_ColorSensor;
    mSetMotor = setMotor;
    mMotorControl = motorControl;
    mLineTrace = lineTrace;
}