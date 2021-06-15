#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include "../headers/toolbox.h"
#include "../headers/constantes.h"
#include "../headers/sound.h"
#include "../headers/widgets.h"

#ifndef PIANO_H
#define PIANO_H

void* metronome();
void* leftHand();
void* rightHand();
void playChords(int usrChords[], int repet[], int bpm);
void playChord(int chord, int inter);
void playNote(int note, int inter);


pthread_t left;
pthread_t right;
pthread_t metro;



#endif