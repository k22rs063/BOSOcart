#include "Section1.h"

Section1::Section1()
{
    state = 0;
}

Section1::~Section1()
{
}


void Section1::exectue()
{
    //mDistance->getEncoder();
    mB_ColorSensor->get_rgb();
    char buf[32];
    //sprintf(buf,"brightness: %d",mB_ColorSensor->get_rgb());
    sprintf(buf,"Section1->state: %d",state);
    mDisplay->text_display(buf);

    switch(state){
        case 0:
        mLineTrace->setParameter(30,0.2,0,1);
        state = 10;
        break;

        case 10:
        mLineTrace->start();
        if(mDistance->getDistance() > 100){
            state = 15;
        }
        break;

        case 15:
        mLineTrace->stop();
        break;
    }
}

bool Section1::isFinished()
{

}