#ifndef SOUND_H
#define SOUND_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <fmod.h>
#include "constantes.h"

void getFrequency(int note, float* frequency, int* octave);
void* playNoteSound(void* arguments);
void* playNoteSoundsec(void* arguments,int second);

FMOD_RESULT result;
FMOD_SYSTEM *systemSound;

#endif
