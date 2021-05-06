#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include "toolbox.h"
#include "constantes.h"
#include "sound.h"
#include "widgets.h"

#ifndef PIANO_H
#define PIANO_H

void* test();
void* leftHand(void* arguments);
void* rightHand(void* arguments);
void playChords(int usrChords[], int repet[], int bpm);
void playChord(int chord, int inter);
void playNote(int note, int inter);
void* displayNote(void* arguments);
int playing;

pthread_t left;
pthread_t right;

#endif