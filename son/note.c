#include <stdlib.h>
#include <stdio.h>
#include "note.h"
#include "inc/fmod.h"

void note1()
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  
  FMOD_RESULT resultat;
  
  /* Création et initialisation d'un objet système */
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  
  /* Chargement du son et vérification du chargement */
  resultat = FMOD_System_CreateSound(system, "notepiano48/1.mp3", FMOD_CREATESAMPLE, 0, &tir);
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


void note2()
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  
  FMOD_RESULT resultat;
  
  /* Création et initialisation d'un objet système */
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  
  /* Chargement du son et vérification du chargement */
  resultat = FMOD_System_CreateSound(system, "notepiano48/2.mp3", FMOD_CREATESAMPLE, 0, &tir);
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

void note3()
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  
  FMOD_RESULT resultat;
  
  /* Création et initialisation d'un objet système */
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  
  /* Chargement du son et vérification du chargement */
  resultat = FMOD_System_CreateSound(system, "notepiano48/3.mp3", FMOD_CREATESAMPLE, 0, &tir);
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

void note4()
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  
  FMOD_RESULT resultat;
  
  /* Création et initialisation d'un objet système */
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  
  /* Chargement du son et vérification du chargement */
  resultat = FMOD_System_CreateSound(system, "notepiano48/4.mp3", FMOD_CREATESAMPLE, 0, &tir);
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
void note5()
{   
  FMOD_SYSTEM *system;
  FMOD_SOUND *tir;
  
  FMOD_RESULT resultat;
  
  /* Création et initialisation d'un objet système */
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  
  /* Chargement du son et vérification du chargement */
  resultat = FMOD_System_CreateSound(system, "notepiano48/5.mp3", FMOD_CREATESAMPLE, 0, &tir);
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















