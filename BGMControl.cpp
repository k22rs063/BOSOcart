#include "BGMControl.h"

BGMControl::BGMControl(Speaker *speaker)
    : mSpeaker(speaker)
{
}

BGMControl::~BGMControl()
{
}

void BGMControl::setBGM(const char *fill)
{
     //ev3_memfile_free(memfile_t *p_memfile);
     ev3_memfile_load(fill, &memfile); //SDカード内の"test.wav"をメモリファイルとしてロード
     ev3_speaker_set_volume(7); //音量の設定
     //ev3_speaker_play_file(p_memfile,duration);
}

void BGMControl::set_blueBGM()
{
    ev3_memfile_load("ev3rt/res/blue.wav", &memfile_blue);
    ev3_speaker_set_volume(15); //音量の設定
}

void BGMControl::set_greenBGM()
{
    ev3_memfile_load("ev3rt/res/green.wav", &memfile_green);
    ev3_speaker_set_volume(15); //音量の設定
}

void BGMControl::set_redBGM()
{
    ev3_memfile_load("ev3rt/res/red.wav", &memfile_red);
    ev3_speaker_set_volume(15); //音量の設定
}

void BGMControl::set_yellowBGM()
{
    ev3_memfile_load("ev3rt/res/yellow.wav", &memfile_yellow);
    ev3_speaker_set_volume(15); //音量の設定
}

void BGMControl::startBGM()
{
    
    ev3_speaker_play_file(&memfile, SOUND_MANUAL_STOP);   
}

void BGMControl::startBGM_blue(){
    ev3_speaker_play_file(&memfile_blue, SOUND_MANUAL_STOP);
}

void BGMControl::startBGM_green(){
    ev3_speaker_play_file(&memfile_green, SOUND_MANUAL_STOP);
}

void BGMControl::startBGM_red(){
    ev3_speaker_play_file(&memfile_red, SOUND_MANUAL_STOP);
}

void BGMControl::startBGM_yellow(){
    ev3_speaker_play_file(&memfile_yellow, SOUND_MANUAL_STOP);
}

void BGMControl::stopBGM(){
    mSpeaker->stop();
}