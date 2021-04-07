#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include "son.h"

void jouerunenote(char *argv)
{

 
   SDL_WM_SetCaption("SDL_Mixer", NULL);
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
   Mix_Music *musique; //Création du pointeur de type Mix_Music
   musique = Mix_LoadMUS(argv); //Chargement de la musique
   Mix_PlayMusic(musique, 1); //Jouer de la musique
   while(1)
     {
       printf("boucle\n");
     }
   Mix_FreeMusic(musique); //Libération de la musique
   Mix_CloseAudio(); //Fermeture de l'API
   SDL_Quit();
}
