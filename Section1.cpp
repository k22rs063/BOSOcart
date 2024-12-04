#include "Section1.h"

Section1::Section1()
{
    state = 0;
}

Section1::~Section1()
{
}


void Section1::execute()
{
    /*
    char buf[32];
    sprintf(buf, "Section1->state: %d", state);
    mDisplay->text_display(buf);
    */
    mB_ColorSensor->get_rgb();
    char buf[64];
    sprintf(buf, "H: %.2f", mB_ColorSensor->get_H());
    ev3_lcd_draw_string(buf,10,10);
    char buf2[64];
    sprintf(buf2, "S: %.2f", mB_ColorSensor->get_S());
    ev3_lcd_draw_string(buf2,10,20);
    char buf3[16];
    sprintf(buf3, "B: %d", mB_ColorSensor->get_rgb());
    ev3_lcd_draw_string(buf3,10,30);
    
    
    switch(state) {
        case 0://直線１
            mLineTrace->setParameter(45, 0.07, 0, 1.5);
            mDistance->start();
            state = 10;
            break;

        case 10://カーブ１
            mLineTrace->start();
            if(mDistance->getDistance() > 265){
                mLineTrace->setParameter(30, 0.43, 0, 3);
                mDistance->start();
                state = 15;
                //state = 100;
            }
            break;

        case 15://直線２
            mLineTrace->start();
            if(mDistance->getDistance() > 80){
                mLineTrace->setParameter(45,0.07,0,1.3);
                mDistance->start();
                state = 20; 
                //state = 100;
            }
            //flag = true;
            break;

        case 20://カーブ２
        mLineTrace->start();
        if(mDistance->getDistance() > 135){
            mLineTrace->setParameter(30,0.4,0,2.5);
            mDistance->start();
            state = 25;
            //state = 100;
        }
        break;

        case 25://直線３
        mLineTrace->start();
        if(mDistance->getDistance() > 80){
            flag = true;
            mLineTrace->stop();
            //state = 100;
        }
        break;

        case 100:
            mLineTrace->stop();
        break;
    }
    
}
bool Section1::isFinished()
{
    return flag;
}