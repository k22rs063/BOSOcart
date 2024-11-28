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
		H = Hue * 100;
	S = Saturation * 100;
  log3 = Brightness * 100;

  return rgb_brightness;
}