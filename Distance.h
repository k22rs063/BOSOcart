#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H
#include "SetMotor.h"
#include <cmath>


class Distance{
    public:
    explicit Distance(SetMotor* setMotor);
    virtual ~Distance();

    void start();
    void stop();
    void getEncoder();
    int getDistance();

    private:
    SetMotor* mSetMotor;
    //モータエンコーダ値を取得
    double left_wheel_angle[2] ={0,0};
    double right_wheel_angle[2] ={0,0};

    //モータの回転角度の変化量
    double delta_left_wheel_angle = 0;
	double delta_right_wheel_angle = 0;

    /* 距離変化量 */
	double delta_left_wheel_distance = 0;
	double delta_right_wheel_distance = 0;
	double delta_distance = 0;
	/* 総走行距離 */
	double distance = 0;
    


    #ifndef M_PI
    #define M_PI (3.14159265358979323846)
    #endif

    #ifndef M_PIl
    #define M_PIl (3.14159265358979323846264338327950288)
    #endif


    const double WHEEL_DIAMETER = 10.0;
	//機体の幅(cm) ← タイヤの接地面間の距離
	double MACHINE_WIDTH = 14.7;

};

#endif