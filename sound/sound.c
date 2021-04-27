#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>
#include "sound.h"

void* fn_thread(void* arg);

int playNote(int nbnote ,char **tabnote)
{
  if (nbnote < 1)
    errx(EXIT_FAILURE, "The number of note is unplayable.");
  else if (nbnote > 10)
    errx(EXIT_FAILURE, "You can't play more than 10 notes");
  
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      printf("%s", Mix_GetError());
    }
  printf("JE commence:!!!");
  Mix_AllocateChannels(15);
  if (nbnote==1)
    {
      Mix_Chunk *note; //Structure Mix_Music correspondante à la note
      note = Mix_LoadWAV(tabnote[0]); //Chargement de la note
      Mix_PlayChannel(1, note, 0); //Jouer la note
      Mix_FreeChunk(note);
       printf("JE JOUEE:!!!");
      return EXIT_SUCCESS;
    }
  else
     {
       printf("JE commence:!!!");
       int index=0;
       while (nbnote!=0)
	 {
	   pthread_t resa;
	   char *note=tabnote[index];
	   index+=1;
	   int sred = pthread_create(&resa,NULL,fn_thread,(void*)note);
	   if (pthread_join(resa, NULL)!=0)
	     {
	       errx(3,"Error during join");
	     }
	   if(sred!=0)
	     {
	       errno=sred;
	       errx(EXIT_FAILURE,"pthread_create()");
	     }
	   nbnote-=1;
	 }  
       pthread_exit(NULL);
     }
  Mix_CloseAudio();
  SDL_Quit();
  return EXIT_SUCCESS;
}

void* fn_thread(void* arg)
{
    char *str1=(char*)arg;
    char *str2=".wav";
    Mix_Chunk *note;
    char *res;
    res=(char *)malloc((strlen(str1)+strlen(str2))*sizeof(char));
    strcpy(res,str1);
    strcat(res,str2);
    note = Mix_LoadWAV(res);
    Mix_PlayChannel(-1,note, 0);
    printf("JE JOUEE:!!!");
    Mix_FreeChunk(note);
    return NULL;
}
/*
int main(int argc, char *argv[])
{
   int continuer = 1;
   SDL_Init(SDL_INIT_VIDEO);
   SDL_Surface *ecran = NULL;
   ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   SDL_Event event;
   SDL_WM_SetCaption("SDL_Mixer", NULL);
   SDL_Flip(ecran);
   if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
   Mix_AllocateChannels(32); //Allouer 32 canaux
   Mix_Volume(1, MIX_MAX_VOLUME/2); //Mettre à mi-volume le post 1
   Mix_Chunk *son;//Créer un pointeur pour stocker un .WAV
   Mix_Chunk *son2;
   son = Mix_LoadWAV("son.wav"); //Charger un wav dans un pointeur
   son2 = Mix_LoadWAV("son2.wav");
   Mix_VolumeChunk(son, MIX_MAX_VOLUME/2); //Mettre un volume pour ce wav
   Mix_VolumeChunk(son2, MIX_MAX_VOLUME);
   while(continuer)
   {
      SDL_WaitEvent(&amp;event);
      switch(event.type)
      {
         case SDL_QUIT:
            continuer = 0;
            break;
         case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
               case SDLK_a:
                  Mix_PlayChannel(1, son, 0);//Joue le son 1 sur le canal 1 ; le joue une fois (0 + 1)
                  break;
               case SDLK_s:
                  Mix_PlayChannel(2, son2, 2);//Joue le son 2 sur le canal 2 ; le joue 3 fois (2 + 1)
                  break;
            }
            break;
      }
   }
   Mix_FreeChunk(son);//Libération du son 1
   Mix_FreeChunk(son2);
   Mix_CloseAudio(); //Fermeture de l'API
   SDL_Quit();
   return EXIT_SUCCESS;
}
*/
