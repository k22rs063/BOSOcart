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
        case 0:
            mLineTrace->setParameter(45, 0.07, 0, 1.3);
            mDistance->start();
            state = 10;
            break;

        case 10:
            mLineTrace->start();
            if(mDistance->getDistance() > 260){
                mLineTrace->setParameter(30, 0.4, 0, 6);
                mDistance->start();
                state = 15;
            }
            break;

        case 15:
            mLineTrace->start();
            if(mDistance->getDistance() > 70){
                mLineTrace->setParameter(45,0.07,0,1.3);
                mDistance->start();
                state = 20;
            }
            //flag = true;
            break;

        case 20:
        mLineTrace->start();
        if(mDistance->getDistance() > 150){
            mLineTrace->setParameter(30,0.4,0,5);
            state = 25;
        }
        break;

        case 25:
        mLineTrace->start();
        if(mDistance->getDistance() > 70){
            flag = true;
            mLineTrace->stop();
        }
        break;
    }
    
}
bool Section1::isFinished()
{
    return flag;
}