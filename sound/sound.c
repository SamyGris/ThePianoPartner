#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include "sound.h"

void playNote(char *argv)
{

   //Initialisation de l'API Mixer
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
   {
      printf("%s", Mix_GetError());
   }
   
   Mix_Music *note; //Structure Mix_Music correspondante à la note
   note = Mix_LoadMUS(argv); //Chargement de la note
   Mix_PlayMusic(note, 1); //Jouer la note
   SDL_Delay(3000);
   
   Mix_FreeMusic(note);
   Mix_CloseAudio();
}
