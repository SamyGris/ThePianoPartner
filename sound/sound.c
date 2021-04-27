#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <err.h>
#include "sound.h"

void* fn_thread(void* arg);

void playNote(char **tabnote,int nbnote)
{
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      printf("%s", Mix_GetError());
    }
  if (nbnote<=1)
    {
      Mix_Music *note; //Structure Mix_Music correspondante à la note
      note = Mix_LoadMUS(tabnote[0]); //Chargement de la note
      Mix_PlayMusic(note, 1); //Jouer la note
      SDL_Delay(3000);
      Mix_FreeMusic(note);
      Mix_CloseAudio();
    }
  else
     {
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
   
}

void* fn_thread(void* arg)
{
    char *str1=(char*)arg;
    char *str2=".mp3";
    Mix_Music *note;
    int i=0;
    for (i = 0; str1[i]!='\0'; i++);
    for (int j = 0; str2[j]!='\0'; j++, i++)
      {
	str1[i] = str2[j];
      }
    str1[i] = '\0';
    note = Mix_LoadMUS(str1); //Chargement de la note
    Mix_PlayMusic(note, 1); //Jouer la note
    SDL_Delay(3000);
    Mix_FreeMusic(note);
    Mix_CloseAudio();
    return NULL;
}
