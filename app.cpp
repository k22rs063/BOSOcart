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
    // gBGMControl->setBGM("ev3rt/res/blue.wav");
    // gBGMControl->startBGM();
    gBGMControl->set_blueBGM();
    gBGMControl->set_greenBGM();
    gBGMControl->set_yellowBGM();
    gBGMControl->set_redBGM();

    //gBGMControl->setBGM("ev3rt/res/r18.wav");
    // gBGMControl->startBGM();

    
    
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
int run_state = 200;//200
memfile_t memfile;
int timer = 0;
int before_color = 5;
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

        //gDisplay->text("runMode");

        /*
        if(gBotton->button_pressed_right()){
            gDisplay->text_reset();
            gDisplay->text("ColorMode");
            run_state = 100;
        }else if(gBotton->button_pressed_left()){
            gDisplay->text_reset();
            gDisplay->text("runMode");
            run_state = 0;
        }
        */



    switch(run_state){

        case 200:
        gDisplay->text("runMode");
        
        if(gBotton->button_pressed_right()){
            gDisplay->text_reset();
            run_state = 205;
        }else if(gBotton->button_pressed_center()){
            run_state = 0;
        }
        break;

        case 205:
        gDisplay->text("ColorMode");
        if(gBotton->button_pressed_left()){
            gDisplay->text_reset();
            run_state = 200;
        }else if(gBotton->button_pressed_center()){
            run_state = 100;
        }
        break;
        
        case 0:
        
        if(gBotton->button_pressed_center()){
            printf("left button pressed\n");
            gBGMControl->setBGM("ev3rt/res/zinguru.wav");
            gBGMControl->startBGM();
            run_state = 10;
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

        case 100:
        if(gBotton->button_pressed_center()){
            gDisplay->text_reset();
            run_state = 105;
        }
        break;
        //色判定モード
        case 105:
        if(gB_ColorSensor->get_Color() == 0){
             gDisplay->text_reset();
             //gDisplay->text("BLUE");
             if(gB_ColorSensor->get_Color() != before_color){
                gBGMControl->startBGM_blue();
             }
            gDisplay->image_load("ev3rt/res/blue2-2.bmp");
    
            before_color = 0;
            run_state = 110;
        }else if(gB_ColorSensor->get_Color() == 2){
             gDisplay->text_reset();
             //gDisplay->text("GREEN");
            gDisplay->image_load("ev3rt/res/green.bmp");
            if(gB_ColorSensor->get_Color() != before_color){
                gBGMControl->startBGM_green();
             }
            before_color = 2;
            run_state = 110;
        }else if(gB_ColorSensor->get_Color() == 1){
             gDisplay->text_reset();
             //gDisplay->text("RED");
            gDisplay->image_load("ev3rt/res/red.bmp");
            if(gB_ColorSensor->get_Color() != before_color){
                gBGMControl->startBGM_red();
                gBGMControl->startBGM();
             }
            before_color = 1;
            run_state = 110;
        }else if(gB_ColorSensor->get_Color() == 3){
             gDisplay->text_reset();
             //gDisplay->text("YELLOW");
            gDisplay->image_load("ev3rt/res/yellow.bmp");
            if(gB_ColorSensor->get_Color() != before_color){
                gBGMControl->startBGM_yellow();
             }
            before_color = 3;
            run_state = 110;
        }else if(gB_ColorSensor->get_Color() == 4){
             gDisplay->text_reset();
             gDisplay->image_load("ev3rt/res/purple.bmp");
             before_color = 4;
             //gDisplay->text("PURPLE");
            //run_state = 130;
            run_state = 110;
        }else{
             gDisplay->text_reset();
             gDisplay->text("NONCOLER");
            //run_state = 135;
        }

        break;

        case 110:
        gDisplay->draw_image();
        run_state = 115;
        //gDisplay->draw_image();
        //run_state = 105;
        break;

        case 115:
        timer++;
        if(timer >= 200){
            run_state = 105;
            timer = 0;
        }
        //run_state = 105;
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