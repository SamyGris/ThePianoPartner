#include "sound.h"

void getFrequency(int note, float* frequency, int* octave)
{
  float douze = 0.083333;
  *octave = note/12;
  note = note % 12;
  *frequency = powf(2,note*douze);
}

void* playNoteSound(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;
  int inter = args->inter;
  float frequency;
  int octave;
  FMOD_SOUND *son;
  getFrequency(note, &frequency, &octave);

  son = samples[octave];  

  FMOD_CHANNEL *channel;
  
  if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
  {
	  errx(3,"Couldn't play the sound");
  }

  if (FMOD_Channel_SetVolume(channel,7.5) != FMOD_OK)
  {
	  errx(3,"Couldn't set the volume"); 
  }
  
  if (FMOD_Channel_SetFrequency(channel,44100) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
    
  if (FMOD_DSP_SetParameterFloat(dsp_effect,0,frequency) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't set the dsp float parametre");
  }

  /*if (FMOD_DSP_SetParameterInt(dsp_effect,1,4096) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't set the dsp int parametre");
  }*/

  if (FMOD_Channel_AddDSP(channel,0,dsp_effect) != FMOD_OK)
  {
	  errx(3,"Couldn't add the DSP to the channel");
  }
  /*
  if (FMOD_Channel_SetDSPIndex(channel,dsp_effect,1) != FMOD_OK)
  {
	  errx(3,"Couldn't set the dsp index in the channel");
  }*/
  msleep(inter);
  pthread_exit(NULL);
  if (FMOD_Sound_Release(son) != FMOD_OK)
  {
    errx(3, "Couldn't release the sound");
  }
}

/*
void *playNoteSoundsec(void *arg,int sec)
{
  struct noteData *args = arg;
  int note = args->note;

  float frequency;
  int octave;

  result = FMOD_System_Create(&systemSound); //Initialisation et création de notre systeme    
  if (result!=FMOD_OK)
    {
      errx(3,"Eroor");
    }
    result=FMOD_System_Init(systemSound,32,FMOD_INIT_NORMAL,NULL); //initialisation du system ne mode lecture normal de son et a 32 channel
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
      result =FMOD_System_CreateSound(systemSound,"notes/DO1.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    case 2 : 
      //noteSound = Mix_LoadMUS("notes/DO2.wav");
      result =FMOD_System_CreateSound(systemSound,"notes/DO2.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    case 3:
      //noteSound = Mix_LoadMUS("notes/DO3.wav");
      result =FMOD_System_CreateSound(systemSound,"notes/DO3.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
    default:
      //noteSound = Mix_LoadMUS("notes/DO4.wav");
      result =FMOD_System_CreateSound(systemSound,"notes/DO4.wav",FMOD_CREATESAMPLE,0,&son);
      if (result!=FMOD_OK)
      {
        errx(3,"Error");
      }
      break;
  }
  return NULL;
}*/

void initAudio()
{
  // Initialisation et création de notre système    
  if (FMOD_System_Create(&systemSound) != FMOD_OK)
  {
    errx(3,"Couldn't create a system");
  }
  
  // Initialisation du système en mode lecture normale de son et à 32 channels
  if (FMOD_System_Init(systemSound,32,FMOD_INIT_NORMAL,NULL) != FMOD_OK)
  {
    errx(3,"Couldn't init a system");
  }

  // Chargement de la banque sonore
  FMOD_SOUND *sound;
  if (FMOD_System_CreateSound(systemSound,"notes/DO1.wav",FMOD_CREATESAMPLE,0, &sound) != FMOD_OK)
  {
    errx(3,"Couldn't create DO1.wav sound");
  }
  samples[0] = sound;


  if (FMOD_System_CreateSound(systemSound,"notes/DO2.wav",FMOD_CREATESAMPLE,0,&sound) != FMOD_OK)
  {
    errx(3,"Couldn't create DO2.wav sound");
  }
  samples[1] = sound;

  if (FMOD_System_CreateSound(systemSound,"notes/DO3.wav",FMOD_CREATESAMPLE,0,&sound) != FMOD_OK)
  {
    errx(3,"Couldn't create DO3.wav sound");
  }
  samples[2] = sound; 

  if (FMOD_System_CreateSound(systemSound,"notes/DO4.wav",FMOD_CREATESAMPLE,0,&sound) != FMOD_OK)
  {
    errx(3,"Couldn't create DO4.wav sound");
  }
  samples[3] = sound; 

  if (FMOD_System_CreateDSPByType(systemSound,FMOD_DSP_TYPE_PITCHSHIFT,&dsp_effect) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't create a dsp ");
  }
}