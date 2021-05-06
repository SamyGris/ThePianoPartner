#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include "constantes.h"
#include "sound.h"
#include "widgets.h"

#ifndef PIANO_H
#define PIANO_H

void* test();
void playChords(int usrChords[], int repet[], int bpm);
void playChord(int chord, int inter);
void playNote(int note, int inter);
void* displayNote(void* arguments);

pthread_t left;

#endif