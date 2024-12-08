#include "B_ColorSensor.h"

B_ColorSensor::B_ColorSensor(ev3api::ColorSensor &colorSensor)
    : mColorSensor(colorSensor)
{
}

B_ColorSensor::~B_ColorSensor()
{
}

int B_ColorSensor::get_brightness()
{
    //sensor_port_t port = mColorSensor.getPort();
    return ev3_color_sensor_get_reflect((sensor_port_t)PORT_2);
}

int B_ColorSensor::get_rgb()
{
    //sensor_port_t port = mColorSensor.getPort();
    mColorSensor.getRawColor(rgb);
	rgb_brightness = (0.299 * rgb.r) + (0.587 * rgb.g) + (0.114 * rgb.b);
	float max = rgb.r > rgb.g ? rgb.r : rgb.g;
	max = max > rgb.b ? max : rgb.b;
	float min = rgb.r < rgb.g ? rgb.r : rgb.g;
	min = min < rgb.b ? min :rgb.b;
	Hue = max - min;
	if (Hue > 0.0f) {
		if (max == rgb.r) {
			Hue = (rgb.g - rgb.b) / Hue;
			if (Hue < 0.0f) {
				Hue += 6.0f;
			}
		} else if (max == rgb.g) {
			Hue = 2.0f + (rgb.b - rgb.r) / Hue;
		} else {
			Hue = 4.0f + (rgb.r - rgb.g) / Hue;
		}
	}
	Hue /= 6.0f;
	Saturation = (max - min);
	if (max != 0.0f)
		Saturation /= max;
		H = Hue * 100 ;
	S = Saturation * 100;
	
  log3 = Brightness * 100;
  syslog(LOG_NOTICE, "%d,%d,%d", (int16_t)H,  (int16_t)S,  (int16_t)rgb_brightness);
  //return H;
  return rgb_brightness;
}

float B_ColorSensor::get_H()
{
	return H;
}

float B_ColorSensor::get_S()
{
	return S;
}

bool B_ColorSensor::Color_blue()
{
	return (H > 43) ? true : false;
}

bool B_ColorSensor::Color_green()
{
	return ((S > 65) && rgb_brightness > 20) ? true : false;//(S > 60) && rgb_brightness > 20
}

bool B_ColorSensor::Color_yellow()
{
	return ((S > 70) && rgb_brightness > 55) ? true : false;
}

bool B_ColorSensor::Color_red()
{
	return ((H < 18) && (S > 65)) ? true : false;
}

bool B_ColorSensor::Color_black()
{
	return (rgb_brightness < 15) ? true : false;
}

bool B_ColorSensor::Color_white()
{
	return (rgb_brightness > 30) ? true : false;
}

bool B_ColorSensor::Color_purple()
{
	return ((S < 37) && (rgb_brightness < 23)) ? true : false;
}

bool B_ColorSensor::Color_blueWhite()
{
	if((S >= 30) && (rgb_brightness > 45)){
		count++;
	}else{
		count = 0;
	}
	if(count >=6){
		return true;
		count = 0;
	}else{
		return false;
	}
}

int B_ColorSensor::get_Color()
{
	// 青色の判定
    if ((H > 40) && (rgb_brightness < 25) && (S > 50) && (rgb_brightness > 5)) {
        return blue;
    }
    // 緑色の判定
    else if ((H > 26) &&(S > 65) && (rgb_brightness > 20)) {
        return green;
    }
    // 赤色の判定
    else if ((H < 10) && (S > 65) && (rgb_brightness < 55) && (rgb_brightness > 5)) {
        return red;
    }
    // 黄色の判定
    else if ((S > 70) && (rgb_brightness > 55)) {
        return yellow;
}else if((S < 30) && (rgb_brightness < 23) && (rgb_brightness > 5) && ((H > 50) || (H < 15))){
		return purple;
	}else {
        return error;
    }


	// if((H > 50) && (rgb_brightness >25)){
	// 	return blue;
	// }else if((S > 65) && rgb_brightness > 20){
	// 	return green;
	// }else if((H < 10) && (S > 65) && rgb_brightness < 55){
	// 	return red;
	// }else if((S > 70) && rgb_brightness > 55){
	// 	return yellow;
	// }else{
	// 	return error;
	// }
}