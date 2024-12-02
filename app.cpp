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
#include "SecondSection.h"
#include "ThirdSection.h"
#include "BGMControl.h"

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
static SecondSection *gSecondSection;
static ThirdSection *gThirdSection;
static BGMControl *gBGMControl;



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
    gSecondSection = new SecondSection();
    gThirdSection = new ThirdSection();
    gBGMControl = new BGMControl(gSpeaker);


    RunAction::setObject(gB_ColorSensor,gSetMotor,gMotorControl,gLineTrace);
    Scene::setObject(gLineTrace,gMotorControl,gB_ColorSensor,gDistance,gDisplay,gBGMControl);
}
bool flag = false;
void main_task(intptr_t unused){
    user_system_create();

    // memfile_t memfile; // メモリファイルの構造体を作成
    // ev3_memfile_load("ev3rt/res/Zing.wav", &memfile); //SDカード内の"test.wav"をメモリファイルとしてロード

    // ev3_speaker_set_volume(10); //音量の設定
    // ev3_speaker_play_file(&memfile, SOUND_MANUAL_STOP); // 音声ファイルを再生

    //gBGMControl->setBGM();
    //gBGMControl->startBGM();
    /*
    while (!flag) {
		tslp_tsk(100*10000U);
	}

    */
    //gDisplay->text_ao();
    
    /*
    gDisplay->image_load("ev3rt/res/momo3.bmp");
    gDisplay->draw_image();
    */
    
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
    gB_ColorSensor->get_rgb();
    /*
    gB_ColorSensor->get_rgb();
    char buf[32];
    sprintf(buf,"brightness: %d",gB_ColorSensor->get_rgb());
    //sprintf(buf,"brightness: %d",run_state);
    gDisplay->text_display(buf);
    */
    if(gBotton->button_pressed_down()){
            run_state=50;
        }



    switch(run_state){
        
        case 0:
        printf("left button pressed\n");
        
        if(gBotton->button_pressed_left()){
            printf("left button pressed\n");
            gBGMControl->setBGM();
            gBGMControl->startBGM();
            run_state = 20;
        }
        break;

        case 10:
        gSection1->execute();
        if(gSection1->isFinished()){
            run_state = 15;
        }
        break;

        case 15:
        gSecondSection->execute();
        if(gSecondSection->isFinished()){
            run_state = 20;
        }
        break;

        case 20:
        gThirdSection->execute();
        if(gThirdSection->isFinished()){
            run_state = 25;
        }
        break;

        case 50:
        gSetMotor->setSpeed(0,0);
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