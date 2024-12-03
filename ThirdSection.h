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
    void LineTrace(int color);
    void turn_right();
    void turn_left();
    void straight();
    void setFlag(bool set_flag);
    bool getFlag();

    const int blue = 0;
    const int green = 1;
    const int red = 2;
    const int yellow = 3;


    int state;
    double circlerush = 2;
    double circle_l = 3;
    int circlestraight = 12;
    int rotate_distance = 5;

    int LineTrace_state = 0;
    int turn_right_state = 0;
    int turn_left_state = 0;
    int straight_state = 0;

    bool function_flag = false;
    bool flag=false;
    //↓ライントレースパラメータ
    int stspeed = 15;//強めのライントレース
    double stp = 0.6;//
    double sti = 0;
    double std = 0.8;//5
    int stdistance = 15;


    int waspeed = 10;//弱めのライントレース
    int wap = 0.1;
    int wai = 0;
    int wad = 2;



};

#endif