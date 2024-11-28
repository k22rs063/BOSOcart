#ifndef LINETRACE_SENSOR_H
#define LINETRACE_SENSOR_H
#include "RunAction.h"
class LineTrace : public RunAction
{
    public:
    explicit LineTrace();
    virtual ~LineTrace();

    void start();
    void stop();
    

    void setParameter(double setspeed,double setkp,double setki,double setkd);

    private:
    double speed;				//速度
	double deceleration;		//目標速度と現在速度の差
	double decelerationKp;
	double decelerationKi;
	double decelerationKd;
	double prev_Speed;			//前回の速度
	double prev_Kp;
	double prev_Ki;
	double prev_Kd;
	double changeSpeed;			//調整後の速度
	double changeKp;
	double changeKi;
	double changeKd;
	double kp = 0.2;					//KPゲイン
	double ki = 0;					//KIゲイン
	double kd = 1;					//KDゲイン
	double target;				//目標値
	int brightness;				//輝度値
	bool run_right_edge_flag;	//走行エッジフラグ
	bool change_speed_flag;		//速度調整有効フラグ
	double turn;				//旋回量

	double integral = 0;		//累積
	double deviation = 0;		//目標値と現在値の偏差
	double prev_deviation = 0;	//前回の偏差
	double prev = 0;	//前回の偏差
};
#endif