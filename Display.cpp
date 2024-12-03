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

void Display::image_load(const char *pass)
{
    ev3_memfile_load(pass, &memfile);
}

bool Display::draw_image()
{
    ev3_image_load(&memfile, &image); // イメージ構造体にファイル構造体を紐づけてろロード
    ev3_lcd_draw_image(&image,0,0); // 座標(x:0, y:0)に画像を表示

    ev3_image_free(&image); // イメージ構造体を解放
}

void Display::text(const char *text2)
{
    ev3_lcd_set_font(EV3_FONT_MEDIUM);
    ev3_lcd_draw_string(text2,10,10);
    ev3_lcd_set_font(EV3_FONT_SMALL);
}

void Display::text_reset()
{
    ev3_lcd_fill_rect(0,0,EV3_LCD_WIDTH,EV3_LCD_HEIGHT,EV3_LCD_WHITE);
}
void Display::text_ao()
{
    // アスキーアートを1行ずつ表示
    for (int i = 0; i < 15; ++i) {
        ev3_lcd_draw_string(ascii_art[i], 0, i * 8);  // 1行ごとに表示
    }

}