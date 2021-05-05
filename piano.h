#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include "constantes.h"
#include "sound.h"
#include "widgets.h"

#ifndef PIANO_H
#define PIANO_H

void init();
void playChords(int usrChords[], int repet[], int* stopped, int bpm);
void playChord(int chord, int inter);
void playNote(int note, int inter);
void test();
void* displayNote(void* arguments);

#endif