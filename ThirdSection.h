#ifndef THIRDSECTION_H
#define THIRDSECTION_H
#include "Scene.h"

class ThirdSection : public Scene{
    public:
    explicit ThirdSection();
    virtual ~ThirdSection();

    void execute();
    bool isFinished();

    private:
    int state;
    int circlerush = 3;
    int circle_l = 0;
    int circlestraight = 12;
    int rotate_distance = 5;
     
    bool flag=false;
    //↓ライントレースパラメータ
    int stspeed = 15;//強めのライントレース
    int stp = 0.7;
    int sti = 0;
    int std = 5;
    int stdistance = 15;


    int waspeed = 10;//弱めのライントレース
    int wap = 0.5;
    int wai = 0;
    int wad = 3;



};

#endif