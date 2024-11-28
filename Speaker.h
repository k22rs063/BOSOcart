#ifndef SPEAKER_H
#define SPEAKER_H
#include "ev3api.h"

class Speaker
{
    public:
    explicit Speaker();
    virtual ~Speaker();
    void set_play_tone(uint16_t frequency, int32_t duration);
    void set_volume(uint8_t volume);
    void play_file(const memfile_t *p_memfile, int32_t duration);
    void stop();
    private:
    int count = 0;
};


#endif