#include "SecondSection.h"

SecondSection::SecondSection()
{
    state = 0;
}

SecondSection::~SecondSection()
{
}


void SecondSection::execute()
{
    char buf[32];
    sprintf(buf, "SecondSection->state: %d", state);
    mDisplay->text_display(buf);
    
    switch(state) {
        case 0:
            mLineTrace->setParameter(20, 0.2, 0, 3);
            mDistance->start();
            state = 10;
            break;

        case 10:
            mLineTrace->start();
            if (mB_ColorSensor->Color_red()) {
                mBGMControl->stopBGM();
                mLineTrace->stop();
                flag = true;
            }
            break;
    }
    
}
bool SecondSection::isFinished()
{
    return flag;
}