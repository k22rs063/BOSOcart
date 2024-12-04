#include "ThirdSection.h"

ThirdSection::ThirdSection()
{
    state = 5;
}

ThirdSection::~ThirdSection()
{
}


void ThirdSection::execute()
{
    // char buf[32];
    // sprintf(buf, "ThirdSection1->state: %d", state);
    // mDisplay->text_display(buf);
    
    switch(state) {

        case 0:
        LineTrace(red);
        if(function_flag){
            state = 5;
            function_flag = false;
        }
        break;


        case 5:
        turn_left();
        if(function_flag){
            state = 6;
            function_flag = false;
            mDistance->start();
            mLineTrace->setParameter(stspeed,0.2,0,3);
        }
        break;

        

        case 6:
        mLineTrace->start();
        if(mDistance->getDistance() > 35){
            mDistance->start();
            mLineTrace->setParameter(stspeed,0.1,0,0.1);
            state = 7;
        }
        
        
        break;

        case 7://1つ目の青
        mLineTrace->start();
        if(mB_ColorSensor->Color_blue()){
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/blue2-2.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_blue();
            state = 10;
            
        }

        break;

        case 10:
        lineStop(blue);
        if(function_flag){
            function_flag = false;
            state = 15;
        }
        break;



        case 15:
        straight();
        if(function_flag){
            function_flag = false;
            state = 20;
        }
        break;

        case 20://２つ目の青
        LineTrace(blue);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/blue2-2.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_blue();
            state = 21;
        }
        break;

        case 21:
        lineStop(blue);
        if(function_flag){
            function_flag = false;
            state = 25;
        }
    
        break;

        case 25:
        straight();
        if(function_flag){
            function_flag = false;
            state = 30;
        }
        break;

        case 30://１つ目の緑
        LineTrace(green);
        if(function_flag){
            function_flag = false;
            state = 31;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/green.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_green();
        }
        break;

        case 31:
        lineStop(green);
        if(function_flag){
            function_flag = false;
            state = 35;
        }
        break;


        case 35:
        straight();
        if(function_flag){
            function_flag = false;
            state = 40;
        }
        break;

        case 40://２つ目の緑
        LineTrace(green);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/green.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_green();
            state = 41;
        }
        break;

        case 41:
        lineStop(green);
        if(function_flag){
            function_flag = false;
            state = 45;
        }
        break;

        case 45:
        turn_right();
        if(function_flag){
            function_flag = false;
            state = 50;
        }
        break;

        case 50://3つ目の緑
        LineTrace(green);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/green.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_green();
            state = 51;
        }
        break;

        case 51:
        lineStop(green);
        if(function_flag){
            function_flag = false;
            state = 55;
        }
        break;

        case 55:
        turn_right();
        if(function_flag){
            function_flag = false;
            state = 60;
        }
        break;

        case 60://１つ目の紫
        LineTrace(purple);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/purple.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_green();
            state = 61;
        }
        break;

        case 61:
        lineStop(green);
        if(function_flag){
            function_flag = false;
            state = 65;
        }
        break;

        case 65:
        straight();
        if(function_flag){
            function_flag = false;
            state = 70;
        }
        break;

        case 70://2つ目の紫
        LineTrace(purple);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/purple.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_blue();
            state = 71;
        }
        break;

        case 71:
        lineStop(blue);
        if(function_flag){
            function_flag = false;
            state = 75;
        }
        break;

        case 75:
        straight();
        if(function_flag){
            function_flag = false;
            state = 80;
        }
        break;

        case 80://４つ目の青
        LineTrace(blue);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/blue2-2.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_blue();
            state = 81;
        }
        break;

        case 81:
        lineStop(blue);
        if(function_flag){
            function_flag = false;
            state = 85;
        }
        break;

        case 85:
        turn_left();
        if(function_flag){
            function_flag = false;
            state = 90;
        }
        break;

        case 90:
            LineTrace(red);//1つ目赤
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/red.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_red();
            state = 91;
            }
        break;

        case 91:
        lineStop(red);
        if(function_flag){
            function_flag = false;
            state = 95;
        }
        break;

        case 95:
            turn_left();
            if(function_flag){
            function_flag = false;
            state = 100;
            }
        break;

        case 100://３つ目紫
            LineTrace(purple);//２つ目赤
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/purple.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_red();
            state = 101;
            }
        break;

        case 101:
        lineStop(red);
        if(function_flag){
            function_flag = false;
            state = 105;
        }
        break;

        case 105:
            straight();
            if(function_flag){
            function_flag = false;
            state = 110;
            }
        break;

        case 110://４つ目紫
            LineTrace(purple);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/purple.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_yellow();
            state = 111;
            }
        break;

        case 111:
        lineStop(yellow);
        if(function_flag){
            function_flag = false;
            state = 115;
        }
        break;

        case 115:
            straight();
            if(function_flag){
            function_flag = false;
            state = 120;
            }
        break;

        case 120://2つ目黄色
            LineTrace(yellow);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/yellow.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_yellow();
            state = 121;
            }
        break;

        case 121:
        lineStop(yellow);
        if(function_flag){
            function_flag = false;
            state = 125;
        }
        break;

        case 125:
            turn_right();
            if(function_flag){
            function_flag = false;
            state = 130;
            }
        break;

        case 130://３つ目黄色
            LineTrace(yellow);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/yellow.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_yellow();
            state = 131;
            }
        break;

        case 131:
        lineStop(yellow);
        if(function_flag){
            function_flag = false;
            state = 135;
        }
        break;

        case 135:
            turn_right();
            if(function_flag){
            function_flag = false;
            state = 140;
            }
        break;

        case 140://4つ目黄色
            LineTrace(yellow);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/yellow.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_yellow();
            state = 141;
            }
        break;

        case 141:
        lineStop(yellow);
        if(function_flag){
            function_flag = false;
            state = 145;
        }
        break;

        case 145:
            straight();
            if(function_flag){
            function_flag = false;
            state = 150;
            }
        break;

        case 150://3つ目赤
            LineTrace(red);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/red.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_red();
            state = 151;
            }
        break;

        case 151:
        lineStop(red);
        if(function_flag){
            function_flag = false;
            state = 155;
        }
        break;

        case 155:
            straight();
            if(function_flag){
            function_flag = false;
            state = 160;
            }
        break;

        case 160://4つ目赤
            LineTrace(red);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/red.bmp");
            mDisplay->draw_image();
            //mBGMControl->startBGM_red();
            state = 165;
            }
        break;

        case 165:
        lineStop(red);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/red.bmp");
            mDisplay->draw_image();
            mMotorControl->setParameter(20,20);
            state = 170;
        }
        break;

        case 170:
        mMotorControl->RotateAction(true);
        if(mB_ColorSensor->Color_black()){
            mMotorControl->stop();
            state = 175;
        }
        break;

        case 175://旋回後1つ目の赤
        LineTrace(red);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/red.bmp");
            mDisplay->draw_image();
            //mMotorControl->setParameter(20,20);
            state = 176;
        }
        break;

        case 176:
        lineStop(red);
        if(function_flag){
            function_flag = false;
            state = 180;
        }
        break;

        case 180:
        straight();
        if(function_flag){
            function_flag = false;
            state = 185;
        }
        break;

        case 185://旋回必要な1つ目の黄色
        LineTrace(yellow);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/yellow.bmp");
            mDisplay->draw_image();
            state = 190;
        }
        break;

        case 190:
        lineStop(yellow);
        if(function_flag){
            function_flag = false;
            state = 195;
        }
        break;

        case 195:
        straight();
        if(function_flag){
            function_flag = false;
            state = 200;
        }
        break;

        case 200:
        LineTrace(yellow);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/yellow.bmp");
            mDisplay->draw_image();
            state = 205;
        }
        break;

        case 205:
        lineStop(yellow);
        if(function_flag){
            state = 9999;
        }
        break;

        


        case 9999:
        mMotorControl->stop();
        break;
    }

        
        
    
}
bool ThirdSection::isFinished()
{
    return flag;
}

void ThirdSection::LineTrace(int color)
{
    switch(LineTrace_state){
        case 0:
        mLineTrace->setParameter(stspeed,0.23,0,4);//0.23,0,4
        mDistance->start();
        LineTrace_state++;

        case 1:
        mLineTrace->start();
        if(mDistance->getDistance() > stdistance){
            LineTrace_state = 2;

        }
        break;

        case 2:
        mLineTrace->setParameter(stspeed,0,0,0);//0.05,0,0.1
        mDistance->start();
        LineTrace_state++;

        case 3:
        mLineTrace->start();
        //mMotorControl->straight();
        if(color == 0 && mB_ColorSensor->Color_blue()){
            function_flag = true;
            LineTrace_state = 0;
        }else if(color == 1 && mB_ColorSensor->Color_green()){
            function_flag = true;
            LineTrace_state = 0;
        }else if(color == 2 && mB_ColorSensor->Color_red()){
            function_flag = true;
            LineTrace_state = 0;
        }else if(color == 3 && mB_ColorSensor->Color_yellow()){
            function_flag = true;
            LineTrace_state = 0;
        }else if(color == 4 && mB_ColorSensor->Color_purple()){
            function_flag = true;
            LineTrace_state = 0;
        }
        break;

    }
}

void ThirdSection::turn_right()
{
    switch(turn_right_state){
        case 0:
        mDistance->start();
        turn_right_state++;

        case 1:
        mMotorControl->straight();
        if(mDistance->getDistance() > circlerush){
            mDistance->start();
            turn_right_state = 5;
        }
        break;

        case 5:
        mMotorControl->turnright();
        if(mB_ColorSensor->Color_black() && mDistance->getDistance() > rotate_distance){
            turn_right_state = 0;
            //mMotorControl->setParameter(10,10);
            function_flag = true;
        }
        break;

        case 7:
        mMotorControl->RotateAction(false);
        if(mB_ColorSensor->Color_white()){
            turn_right_state = 0;
            function_flag = true;
        }
        break;
    }
}

void ThirdSection::turn_left()
{
    switch(turn_left_state){
        case 0:
        mDistance->start();
        turn_left_state++;

        case 1:
        mMotorControl->straight();
        if(mDistance->getDistance() > circle_l){
            mDistance->start();
            turn_left_state = 5;
        }
        break;

        case 5:
        mMotorControl->trunleft();
        if(mB_ColorSensor->Color_black() && mDistance->getDistance() > rotate_distance){
            mMotorControl->setParameter(10,10);
            turn_left_state = 10;
        }
        break;

        case 10:
        mMotorControl->RotateAction(true);
        if(mB_ColorSensor->Color_white()){
            turn_left_state = 0;
            function_flag = true;
        }
        break;
    }
}

void ThirdSection::straight()
{
    switch(straight_state){
        case 0:
        mDistance->start();
        straight_state = 5;

        case 5:
        mMotorControl->straight();
        if(mDistance->getDistance() > circlestraight){
            straight_state = 0;
            function_flag = true;
        }
        break;
    }
}

void ThirdSection::lineStop(int color)
{
    switch(lineStop_state){

        case 0:
        mLineTrace->stop();
        if(color == 0){
            mBGMControl->startBGM_blue();
            lineStop_state = 5;
        }else if(color == 1){
            mBGMControl->startBGM_green();
            lineStop_state = 5;
        }else if(color == 2){
            mBGMControl->startBGM_red();
            lineStop_state = 5;
        }else{
            mBGMControl->startBGM_yellow();
            lineStop_state = 5;
        }
        break;
        case 5:
        mLineTrace->stop();
        counter++;
            if(counter >= 100){
                function_flag =true;
                counter = 0;
                lineStop_state = 0;
            }
        break;
    }
}

void ThirdSection::setFlag(bool set_flag)
{
    function_flag = set_flag;
}

bool ThirdSection::getFlag()
{
    return function_flag;
}