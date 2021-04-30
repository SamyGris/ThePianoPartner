#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "SDL/SDL.h" 
#include "SDL/SDL_mixer.h"
#include "sound.h"
#include "constantes.h"

void getFrequency(int note, int* frequency, int* octave)
{
  float coeff = 1.05946;

  *octave = note/12 + 1;
  note = note % 12;
  *frequency = 44000;

  for (int i = 0; i < note; i++)
    *frequency *= coeff;
}

void* playNoteSound(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;

  int frequency;
  int octave;

  getFrequency(note, &frequency, &octave);

  //Initialisation de l'API Mixer
  if(Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
  {
    printf("%s", Mix_GetError());
  }
   
  Mix_Music *noteSound; //Structure Mix_Music correspondante à la note

  switch (octave)
  {
    case 1:
      noteSound = Mix_LoadMUS("notes/DO1.wav");
      break;
    case 2 : 
      noteSound = Mix_LoadMUS("notes/DO2.wav");
      break;
    case 3:
      noteSound = Mix_LoadMUS("notes/DO3.wav");
      break;
    default:
      noteSound = Mix_LoadMUS("notes/DO4.wav");
      break;
  }
  
  Mix_PlayMusic(noteSound, 1);//Jouer la note
   
  SDL_Delay(3000);
  Mix_FreeMusic(noteSound);
  Mix_CloseAudio();

  pthread_exit(NULL);
  return NULL;
}