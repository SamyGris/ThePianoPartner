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
#include "toolbox.h"

void getDemitone(int note, float* demitone, int* octave);
void* playNoteSound(void* arguments);
void playNoteSoundSec(int note, int inter);
void initAudio(); 
void updateAudio();

FMOD_SYSTEM *systemSound;
FMOD_DSP *dsp_effect;
FMOD_SOUND *samples[4]; 

#endif
