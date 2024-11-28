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

    private:
    rgb_raw_t rgb;
    float Hue;
	float Saturation;
	float Brightness;
    int max;
    int min;
    int rgb_brightness;

    int H;
	int S;
	int log3;


    ev3api::ColorSensor &mColorSensor;
};


#endif