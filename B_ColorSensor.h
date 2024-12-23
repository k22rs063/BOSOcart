#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H
#include "ev3api.h"
#include "ColorSensor.h"
class B_ColorSensor
{
    public:
    explicit B_ColorSensor(ev3api::ColorSensor &colorSensor);
    virtual ~B_ColorSensor();
    int get_brightness();
    int get_rgb();
    float get_H();
    float get_S();
    bool Color_blue();
    bool Color_green();
    bool Color_yellow();
    bool Color_red();
    bool Color_black();
    bool Color_white();
    bool Color_purple();

    bool Color_blueWhite();
    int get_Color();

    private:
    const int blue = 0;
    const int red = 1;
    const int green = 2;
    const int yellow = 3;
    const int purple = 4;
    const int error = 5;
    rgb_raw_t rgb;
    float Hue;
	float Saturation;
	float Brightness;
    int max;
    int min;
    int rgb_brightness;

    int count = 0;

    int H;
	int S;
	int log3;


    ev3api::ColorSensor &mColorSensor;
};


#endif