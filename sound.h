#ifndef SOUND_H
#define SOUND_H


void getFrequency(int note, float* frequency, int* octave);
void* playNoteSound(void* arguments);
void* playNoteSoundsec(void* arguments,int second);
#endif