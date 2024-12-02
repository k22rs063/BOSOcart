#ifndef BGMCONTROL_H
#define BGMCONTROL_H

#include "ev3api.h"
#include "Speaker.h"
class BGMControl
{
    public:
    explicit BGMControl(Speaker *speaker);
    virtual ~BGMControl();
    void setBGM();
    void startBGM();
    private:
    Speaker *mSpeaker;
    memfile_t memfile;
};
#endif