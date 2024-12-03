#include "BGMControl.h"

BGMControl::BGMControl(Speaker *speaker)
    : mSpeaker(speaker)
{
}

BGMControl::~BGMControl()
{
}

void BGMControl::setBGM()
{
     //ev3_memfile_free(memfile_t *p_memfile);
     ev3_memfile_load("ev3rt/res/rairac.wav", &memfile); //SDカード内の"test.wav"をメモリファイルとしてロード
     //ev3_speaker_play_file(p_memfile,duration);
}

void BGMControl::startBGM()
{
    ev3_speaker_set_volume(7); //音量の設定
    
    ev3_speaker_play_file(&memfile, SOUND_MANUAL_STOP);   
}
