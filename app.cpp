#include "app.h"
#include "ev3api.h"
#include "SetMotor.h"
#include "Motor.h"
#include "stdio.h"
#include "B_ColorSensor.h"
#include "Display.h"
#include "Botton.h"
#include "LineTrace.h"
#include "RunAction.h"
#include "Speaker.h"
#include "MotorControl.h"
#include "Distance.h"
#include "Scene.h"
#include "Section1.h"

// using ev3api::Clock;
using ev3api::ColorSensor;
// using ev3api::GyroSensor;

using ev3api::Motor;
//using ev3api::TouchSensor;

// Device objects
// オブジェクトを静的に確保する
//Motor gArmMotor(PORT_A);
Motor gRightWheel(PORT_B);
ColorSensor gColorSensor(PORT_2);
Motor gLeftWheel(PORT_C);
//GyroSensor gGyroSensor(PORT_4);

static SetMotor *gSetMotor;
static B_ColorSensor *gB_ColorSensor;
static Botton *gBotton;
static Display *gDisplay;
static LineTrace *gLineTrace;
static Speaker *gSpeaker;
static MotorControl *gMotorControl;
static Distance *gDistance;
static Section1 *gSection1;



static void user_system_create()
{

    // SetMotor setMotor(gLeftWheel,gRightWheel);
    // B_ColorSensor colorsensor(gColorSensor);
    // Display display;
    // Botton button;
    // LineTrace lineTrace;


    // RunAction::setObject(&colorsensor,&setMotor);
    gSetMotor = new SetMotor(gLeftWheel,gRightWheel);
    gB_ColorSensor = new B_ColorSensor(gColorSensor);
    gDisplay = new Display();
    gBotton = new Botton();
    gLineTrace = new LineTrace();
    gSpeaker = new Speaker();
    gMotorControl = new MotorControl();
    gDistance = new Distance(gSetMotor);
    gSection1 = new Section1();


    RunAction::setObject(gB_ColorSensor,gSetMotor,gMotorControl,gLineTrace);
    Scene::setObject(gLineTrace,gMotorControl,gB_ColorSensor,gDistance,gDisplay);
}
void main_task(intptr_t unused){
    user_system_create();


    sta_cyc(EV3_CYC_RUN);
    slp_tsk();
    stp_cyc(EV3_CYC_RUN);

    //user_system_destroy();

	// タスク終了
	ext_tsk();

    //オブジェクトの生成
    // SetMotor setMotor(gLeftWheel,gRightWheel);
    // B_ColorSensor colorsensor(gColorSensor);
    // Display display;
    // Botton button;
    // LineTrace lineTrace;


    // RunAction::setObject(&colorsensor,&setMotor);
    
}
int run_state = 0;
memfile_t memfile;

void run_task(intptr_t unused){
    gDistance->getEncoder();
    /*
    gB_ColorSensor->get_rgb();
    char buf[32];
    sprintf(buf,"brightness: %d",gB_ColorSensor->get_rgb());
    //sprintf(buf,"brightness: %d",run_state);
    gDisplay->text_display(buf);
    */


    switch(run_state){
        
        /*
        case 0:
        if(gBotton->button_pressed_left()){
            gSpeaker->set_volume(30);
            //gSpeaker->set_play_tone(NOTE_G6,30);
            run_state = 5;
            gDistance->start();
            gLineTrace->setParameter(10,0.2,0,1);
        }

        break;
        */

        case 0:
        printf("left button pressed\n");
         
        if(gBotton->button_pressed_left()){
            printf("left button pressed\n");
            // char buf[32];
            // sprintf(buf,"brightness: %d",gB_ColorSensor->get_rgb());
            // gDisplay->text_display(buf);
            //sprintf(buf,"brightness: %d",run_state);
            //gLineTrace->setParameter(20,0.2,0,1);
            
            run_state = 10;
        }
        break;

        case 10:
        gSection1->exectue();
        if(gSection1->isFinished()){
            run_state = 15;
        }
        break;
    }
    /*
    int count = 0;
    char buf[32];
    while(!gBotton->button_pressed_center()){

    }
    gLineTrace->start();
    sprintf(buf,"brightness: %d",gB_ColorSensor->get_rgb());
    gDisplay->text_display(buf);
    count++;
    */
    
    //setMotor.setSpeed(0,0);
    
}