#include "ThirdSection.h"

ThirdSection::ThirdSection()
{
    state = 0;
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
            state = 35;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/green.bmp");
            mDisplay->draw_image();
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

        case 60://４つ目の緑
        LineTrace(green);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/green.bmp");
            mDisplay->draw_image();
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

        case 70://３つ目の青
        LineTrace(blue);
        if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/blue2-2.bmp");
            mDisplay->draw_image();
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

        case 100:
            LineTrace(red);//２つ目赤
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/red.bmp");
            mDisplay->draw_image();
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

        case 110://一つ目黄色
            LineTrace(yellow);
            if(function_flag){
            function_flag = false;
            mDisplay->text_reset();
            mDisplay->image_load("ev3rt/res/yellow.bmp");
            mDisplay->draw_image();
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
        mLineTrace->setParameter(stspeed,0.23,0,4);
        mDistance->start();
        LineTrace_state++;

        case 1:
        mLineTrace->start();
        if(mDistance->getDistance() > stdistance){
            LineTrace_state = 2;

        }
        break;

        case 2:
        mLineTrace->setParameter(stspeed,0.1,0,0.1);
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

void ThirdSection::setFlag(bool set_flag)
{
    function_flag = set_flag;
}

bool ThirdSection::getFlag()
{
    return function_flag;
}