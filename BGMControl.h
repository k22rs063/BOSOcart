#ifndef BGMCONTROL_H
#define BGMCONTROL_H

#include "ev3api.h"
#include "Speaker.h"
class BGMControl
{
    public:
    explicit BGMControl(Speaker *speaker);
    virtual ~BGMControl();
    void setBGM(const char *file);
    void set_blueBGM();
    void set_greenBGM();
    void set_yellowBGM();
    void set_redBGM();
    void startBGM();
    void startBGM_blue();
    void startBGM_green();
    void startBGM_red();
    void startBGM_yellow();
    void stopBGM();

    private:
    Speaker *mSpeaker;
    memfile_t memfile;
    memfile_t memfile_blue;
    memfile_t memfile_green;
    memfile_t memfile_red;
    memfile_t memfile_yellow;

};
#endif