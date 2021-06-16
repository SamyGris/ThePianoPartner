#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <stdio.h>
#include <time.h>
#include <err.h>
#include <errno.h>
#include "constantes.h"

int msleep(int tms);
void initFileText(); 
char* getLengthNote(int l); 
 
#endif