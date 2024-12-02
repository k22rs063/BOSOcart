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
    char buf[32];
    sprintf(buf, "ThirdSection1->state: %d", state);
    mDisplay->text_display(buf);
    
    switch(state) {

        case 0:
        mLineTrace->setParameter(stspeed,stp,sti,std);
        state = 1;
        break;

        case 1:
            mLineTrace->start();
            if(mB_ColorSensor->Color_red()){
                mDistance->start();
                state = 2;
        }
        break;

        case 2:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlerush){
                mDistance->start();
                state = 5;
            }
            break;

        case 5:
            mMotorControl->trunleft();
            if(mB_ColorSensor->Color_black()){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mMotorControl->setParameter(10,10);
                mDistance->start();
                state = 6;
            }
            break;

            case 6:
            mMotorControl->RotateAction(true);
            if(mB_ColorSensor->Color_white()){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 10;
            }
            break;


        case 10:
            mLineTrace->start();
            if(mDistance->getDistance() > 35){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 15;
            }
            break;
        
        

        case 15:
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_blue()){
                mDistance->start();
                state = 20;
            }
            break;

        case 20:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlestraight){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 25;
            }
            break;

        case 25:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                mDistance->start();
                state = 30;
            }
            break;

        case 30:
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_blue()){
                mDistance->start();
                //mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 35;
            }
            break;

        case 35:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlestraight){//ふたつめ
                mDistance->start();
                mLineTrace->setParameter(stspeed,stp,sti,std);
                state = 40;
            }
            break;

        case 40:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 45;
            }
            break;

        case 45://一つ目緑
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_green()){
                mDistance->start();
                state = 50;
            }
            break;

        case 50:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlestraight){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 55;
            }
            break;

        case 55:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mDistance->start();
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 60;
            }
            break;

        case 60://二つ目緑
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_green()){
                mDistance->start();
                state = 65;
            }
            break;

        case 65:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlerush){
                mDistance->start();
                state = 70;
            }
            break;

        case 70:
            mMotorControl->turnright();
            if(mB_ColorSensor->Color_black() && mDistance->getDistance() > rotate_distance){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 75;
            }
            break;

        case 75:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                mDistance->start();
                state = 80;
            }
            break;

        case 80://1列目
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_green()){
                mDistance->start();
                //mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 85;
            }
            break;

        case 85:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlerush){
                mDistance->start();
                state = 90;
            }
            break;

        case 90://2列目
            mMotorControl->turnright();
            if(mB_ColorSensor->Color_black()){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 95;
            }
            break;

        case 95:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                mDistance->start();
                state = 100;
            }
            break;

        case 100://４つ目の緑円
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_green()){
                mDistance->start();
                //mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 105;
            }
            break;

        case 105:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlestraight){
                mDistance->start();
                mLineTrace->setParameter(stspeed,stp,sti,std);
                state = 110;
            }
            break;

        case 110:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 115;
            }
            break;

        case 115:
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_blue()){
                mDistance->start();
                state = 120;
            }
            break;

        case 120:
            mMotorControl->straight();
            if(mDistance->getDistance() > circlestraight){
                mDistance->start();
                mLineTrace->setParameter(stspeed,stp,sti,std);
                state = 125;
            }
            break;

        case 125:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 130;
            }
            break;

        case 130://２列目
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_blue()){
                mDistance->start();
                state = 135;
            }
            break;


        case 135:
            mMotorControl->straight();
            if(mDistance->getDistance() > circle_l){
                mDistance->start();
                state = 140;
            }
            break;

        case 140:
            mMotorControl->trunleft();
            if(mB_ColorSensor->Color_black() && mDistance->getDistance() > rotate_distance){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mMotorControl->setParameter(30,30);
                mDistance->start();
                state = 141;
            }
            break;

            case 141:
            mMotorControl->RotateAction(true);
            if(mB_ColorSensor->Color_white()){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 145;
            }
            break;

        case 145:
            mLineTrace->start();
            if(mDistance->getDistance() > stdistance && mDistance->getDistance() > rotate_distance){
                mLineTrace->setParameter(waspeed,wap,wai,wad);
                mDistance->start();
                state = 150;
            }
            break;

        case 150:
            //mLineTrace->start();
            mMotorControl->straight();
            if(mB_ColorSensor->Color_red()){
                mDistance->start();
                //mLineTrace->setParameter(waspeed,wap,wai,wad);
                state = 160;
            }
            break;

        case 160:
            mMotorControl->straight();
            if(mDistance->getDistance() > circle_l){
                mDistance->start();
                state = 170;
            }
            break;

        case 170:
            mMotorControl->trunleft();
            if(mB_ColorSensor->Color_black()){
                mLineTrace->setParameter(stspeed,stp,sti,std);
                mDistance->start();
                state = 9999;
            }
            break;


        case 9999:
            mLineTrace->stop();
            break;
    }
    
}
bool ThirdSection::isFinished()
{
    return flag;
}