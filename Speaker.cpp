#include "Speaker.h"
Speaker::Speaker()
{
}

Speaker::~Speaker()
{
}

void Speaker::set_play_tone(uint16_t frequency, int32_t duration)
{
    ev3_speaker_play_tone(frequency,duration);
}

void Speaker::set_volume(uint8_t volume)
{
    ev3_speaker_set_volume(volume);
}

void Speaker::play_file(const memfile_t *p_memfile, int32_t duration)
{
    ev3_speaker_play_file(p_memfile,duration);
}

void Speaker::stop()
{
    ev3_speaker_stop();
}
