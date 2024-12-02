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
            mLineTrace->setParameter(50, 0.2, 0, 1);
            mDistance->start();
            state = 10;
            break;

        case 10:
            mLineTrace->start();
            if (mDistance->getDistance() > 50) {
                state = 15;
            }
            break;

        case 15:
            mLineTrace->stop();
            flag = true;
            break;
    }
    
}
bool SecondSection::isFinished()
{
    return flag;
}