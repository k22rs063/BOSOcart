#ifndef DISPLAY_SENSOR_H
#define DISPLAY_SENSOR_H

#include "ev3api.h"

class Display
{
    public:
    explicit Display();
    virtual ~Display();
    void text_display(const char *text);
    void image_load(const char *pass);
    void draw_image();
    void text_ao();


    private:
    memfile_t memfile;
    image_t image;
    int count = 0;
     // アスキーアートを行ごとの文字列として格納
    // アスキーアートを行ごとの文字列として格納
       const char* ascii_art[15] = {
    "//         .++:                    ..                    ",
    "//          .#%-                   =##-        .         ",
    "//     .     ##. .-*#-              =@*       .=*+-      ",
    "//     -*+===%#+###+-.              -%=          -%%=    ",
    "//      .-==+%+:...            :.   -%=-*%#:      .#@+   ",
    "//          -%: .-#=.          :****#@#*=-.        :*=   ",
    "//          =@++++%%++*=.        .::-%:                   ",
    "//       :+*#%.  -%+  .=%+.         -%:  .:-===-:        ",
    "//     :##- =%. :%*.    :%*.        -%++*#*+===*%%=.     ",
    "//    =%=   =%.:%+.     .*@:      :=#@+:        .+@*     ",
    "//   =%=    =%=#=       .*@:    -*+:=%:          .#%-    ",
    "//  .%#     =@*.        :%#.   +*.  -%:          .#%:    ",
    "//  :%*  .-*#@+        :%#:    +*.  =%:          =%+     ",
    "//  .*%#**=.-%*     .:*#+.      =#=-*%.  -=-::-+#%=      ",
    "//    ::.   .=: .-=+*+-.         .=*+.    :=+**+-.        "
};

    
};
#endif