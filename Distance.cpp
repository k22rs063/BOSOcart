#include "Distance.h"

Distance::Distance(SetMotor *setMotor)
    : mSetMotor(setMotor)
{
}
Distance::~Distance()
{
}

void Distance::start()
{
   distance = 0;
}

void Distance::stop()
{
    distance = 0;
}

int Distance::getEncoder()
{
    right_wheel_angle[1] = mSetMotor->getRinghtEncoder();
	left_wheel_angle[1] = mSetMotor->getLeftEncoder();

    //右モータの回転角度変化量を計算
	delta_right_wheel_angle = right_wheel_angle[1] - right_wheel_angle[0];
	//右モータの過去のエンコーダ値を更新
	right_wheel_angle[0] = right_wheel_angle[1];
	//左モータの角度変化量変化量を計算
	delta_left_wheel_angle = left_wheel_angle[1] - left_wheel_angle[0];
	//左モータの過去のエンコーダ値を更新
	left_wheel_angle[0] = left_wheel_angle[1];

	//右タイヤの距離変化量を計算
	delta_right_wheel_distance = delta_right_wheel_angle * M_PI * WHEEL_DIAMETER / 360.0;
	//左タイヤの距離変化量を計算
	delta_left_wheel_distance = delta_left_wheel_angle * M_PI * WHEEL_DIAMETER / 360.0;
	//走行体の距離変化量を計算
	delta_distance = (delta_right_wheel_distance + delta_left_wheel_distance) / 2.0;
	//走行体の走行距離を計算
	distance += delta_distance;
}

int Distance::getDistance()
{
    return distance;
}

