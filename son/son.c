#include <stdlib.h>
#include <stdio.h>
#include "inc/fmod.h"
#include "son.h"

void jouerunenote(char *argv)
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  FMOD_RESULT resultat;

  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);

  resultat = FMOD_System_CreateSound(system, argv,FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &tir);
  if (resultat != FMOD_OK)
    {
      fprintf(stderr, "Impossible de lire le son\n");
      exit(EXIT_FAILURE);
    }
  
  FMOD_System_PlaySound(system, NULL, tir, 0, NULL);
  FMOD_Sound_Release(tir);
  FMOD_System_Close(system);
  FMOD_System_Release(system);
}
