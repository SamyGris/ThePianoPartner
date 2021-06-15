#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "toolbox.h"
#include "constantes.h"
#include "sound.h"
#include "widgets.h"

#ifndef PIANO_H
#define PIANO_H

void* metronome();
void* metrofunction();
void* leftHand();
void* rightHand();
void playChords(int usrChords[], int repet[], int bpm);
void playChord(int chord, int inter);
void playNote(int note, int inter);


pthread_t left;
pthread_t right;
pthread_t metro;



#endif