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

void* test();
void* test2(int note,int duree);
void* leftHand();
void* rightHand();
void playChords(int usrChords[], int repet[], int bpm);
void playChord(int chord, int inter);
void playNote(int note, int inter);
void* displayNote(void* arguments);
void getChords(); 
void getScale(); 
int playing;

pthread_t left;
pthread_t right;

struct songData song;

#endif