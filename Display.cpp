#include "Display.h"
Display::Display()
{
}

Display::~Display()
{
}

void Display::text_display(const char *text)
{
    count++;
    ev3_lcd_draw_string(text,10,10*count);
    if(count >= 12){
        count = 0;
    }
}