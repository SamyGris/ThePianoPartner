#include <stdlib.h>
#include <stdio.h>
#include "inc/fmod.h"
#include "main.h"

void jouerunenote(char *argv[])
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  FMOD_RESULT resultat;
  /* Création et initialisation d'un objet système */
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  /* Chargement du son et vérification du chargement */
  resultat = FMOD_System_CreateSound(system, argv[1], FMOD_CREATESAMPLE, 0, &tir);
  if (resultat != FMOD_OK)
    {
      fprintf(stderr, "Impossible de lire pan.wav\n");
      exit(EXIT_FAILURE);
    }
  FMOD_System_PlaySound(system, NULL, tir, 0, NULL);
  FMOD_Sound_Release(tir);
  FMOD_System_Close(system);
  FMOD_System_Release(system);
}


