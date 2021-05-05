#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <err.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <fmod.h>
#include "sound.h"
#include "constantes.h"

void getFrequency(int note, float* frequency, int* octave)
{
  /*float coeff = 1.05946;

  *octave = note/12 + 1;
  note = note % 12;
  *frequency = 44000;

  for (int i = 0; i < note; i++)
    *frequency *= coeff;*/

   float douze = 0.083333;
  *octave = note/12 + 1;
  note = note % 12;
  *frequency = powf(2,note*douze);

  
}

void* playNoteSound(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;

  float frequency;
  int octave;

  FMOD_RESULT result;
  FMOD_SYSTEM *system =NULL;
  result = FMOD_System_Create(&system); //Initialisation et création de notre systeme    
  if (result!=FMOD_OK)
    {
      errx(3,"Eroor");
    }
    result=FMOD_System_Init(system,32,FMOD_INIT_NORMAL,NULL); //initialisation du system ne mode lecture normal de son et a 32 channel
    if (result!=FMOD_OK)
    {
      errx(3,"Erroe");
    }


  getFrequency(note, &frequency, &octave);

  /*if(Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
  {
    printf("%s", Mix_GetError());
  }*/
   
  FMOD_SOUND *son=NULL;  //Structure FMOD_SOUND correspondante à la note

  switch (octave)
  {
    case 1:
      //noteSound = Mix_LoadMUS("notes/DO1.wav");
      result =FMOD_System_CreateSound(system,"DO1.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    case 2 : 
      //noteSound = Mix_LoadMUS("notes/DO2.wav");
      result =FMOD_System_CreateSound(system,"DO2.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    case 3:
      //noteSound = Mix_LoadMUS("notes/DO3.wav");
      result =FMOD_System_CreateSound(system,"DO3.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    default:
      //noteSound = Mix_LoadMUS("notes/DO4.wav");
      result =FMOD_System_CreateSound(system,"DO4.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
  }
  
  //Mix_PlayMusic(noteSound, 1);//Jouer la note
  
  FMOD_CHANNELGROUP *channelgroup;

  result=FMOD_System_GetMasterChannelGroup(system,&channelgroup);
  if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }
  FMOD_CHANNEL *reyane;
  result=FMOD_System_PlaySound(system,son,channelgroup,0,&reyane);
  if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }
  result=FMOD_Channel_SetVolume(reyane,7.5);
  if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }
  result=FMOD_Channel_SetFrequency(reyane,44100);
  if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }
    FMOD_DSP *dsp_effect;

    result=FMOD_System_CreateDSPByType(system,FMOD_DSP_TYPE_PITCHSHIFT,&dsp_effect);
    if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }

    result=FMOD_DSP_SetParameterFloat(dsp_effect,0,frequency);

    if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }

    result=FMOD_DSP_SetParameterInt(dsp_effect,1,4096);

    if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }

    result=FMOD_Channel_AddDSP(reyane,0,dsp_effect);
     if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }
    result=FMOD_Channel_SetDSPIndex(reyane,dsp_effect,1);
     if (result!=FMOD_OK)
      {
	    errx(3,"Erroe");
      }
  FMOD_BOOL vrai;
  FMOD_Channel_IsPlaying(reyane,&vrai);

  while(1)
      {
	      if(vrai==0)
	      {
	        FMOD_Sound_Release(son);
	        break;
	      }
	      FMOD_Channel_IsPlaying(reyane,&vrai);
      }
    FMOD_System_Close(system);
    FMOD_System_Release(system);
  /*SDL_Delay(3000);
  Mix_FreeMusic(noteSound);
  Mix_CloseAudio();*/

  pthread_exit(NULL);
  return NULL;
}

void *playNoteSoundsec(void *arg,int sec)
{
  struct noteData *args = arg;
  int note = args->note;

  float frequency;
  int octave;

  FMOD_RESULT result;
  FMOD_SYSTEM *system =NULL;
  result = FMOD_System_Create(&system); //Initialisation et création de notre systeme    
  if (result!=FMOD_OK)
    {
      errx(3,"Eroor");
    }
    result=FMOD_System_Init(system,32,FMOD_INIT_NORMAL,NULL); //initialisation du system ne mode lecture normal de son et a 32 channel
    if (result!=FMOD_OK)
    {
      errx(3,"Erroe");
    }

  printf("%d",sec); //anti warning
  getFrequency(note, &frequency, &octave);

  FMOD_SOUND *son=NULL;  //Structure FMOD_SOUND correspondante à la note

  switch (octave)
  {
    case 1:
      //noteSound = Mix_LoadMUS("notes/DO1.wav");
      result =FMOD_System_CreateSound(system,"DO1.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    case 2 : 
      //noteSound = Mix_LoadMUS("notes/DO2.wav");
      result =FMOD_System_CreateSound(system,"DO2.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    case 3:
      //noteSound = Mix_LoadMUS("notes/DO3.wav");
      result =FMOD_System_CreateSound(system,"DO3.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    default:
      //noteSound = Mix_LoadMUS("notes/DO4.wav");
      result =FMOD_System_CreateSound(system,"DO4.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
  }
  return NULL;
}