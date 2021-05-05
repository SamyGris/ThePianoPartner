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
  float frequency;
  int octave;
  FMOD_SOUND *son;
  getFrequency(note, &frequency, &octave);

  son = samples[octave];  

  
  FMOD_CHANNEL *reyane;
  result=FMOD_System_PlaySound(systemSound,son,NULL,0,&reyane);
  if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't play the sound");
      }
  result=FMOD_Channel_SetVolume(reyane,7.5);
  if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't set the volume"); 

      }
  result=FMOD_Channel_SetFrequency(reyane,44100);
  if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't set the frequency");
      }
    FMOD_DSP *dsp_effect;

    result=FMOD_System_CreateDSPByType(systemSound,FMOD_DSP_TYPE_PITCHSHIFT,&dsp_effect);
    if (result!=FMOD_OK)
      {
	    errx(3,"Signal analyse : couldn't create a dsp ");
      }

    result=FMOD_DSP_SetParameterFloat(dsp_effect,0,frequency);

    if (result!=FMOD_OK)
      {
	    errx(3,"Signal analyse : couldn't set the dsp float parametre");
      }

    /*result=FMOD_DSP_SetParameterInt(dsp_effect,1,4096);

    if (result!=FMOD_OK)
      {
	    errx(3,"Signal analyse : couldn't set the dsp int parametre");
      }*/

    result=FMOD_Channel_AddDSP(reyane,0,dsp_effect);
     if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't add the DSP to the channel");
      }
    result=FMOD_Channel_SetDSPIndex(reyane,dsp_effect,1);

     if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't set the dsp index in the channel");
      }
  FMOD_BOOL vrai;
  FMOD_Channel_IsPlaying(reyane,&vrai);

  while(1)
      {
	      if(vrai==0)
	      {
	        result = FMOD_Sound_Release(son);
          if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't release the sound");
      }
	        break;
	      }
	      result =FMOD_Channel_IsPlaying(reyane,&vrai);
        if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't say if the channel is playing");
      }
      }
    result=FMOD_System_Close(systemSound);
    if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't close the system");
      }
    FMOD_System_Release(systemSound);
    if (result!=FMOD_OK)
      {
	    errx(3,"Couldn't release the system");
      }

  pthread_exit(NULL);
  return NULL;
}

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
}

void initAudio()
{
  FMOD_SOUND *sound; 
  result = FMOD_System_CreateSound(systemSound,"notes/DO1.wav",FMOD_CREATESAMPLE,0, &sound);
  if (result != FMOD_OK)
  {
    errx(3,"Couldn't create DO1.wav sound");
  }
  samples[0] = sound; 
  result = FMOD_System_CreateSound(systemSound,"notes/DO2.wav",FMOD_CREATESAMPLE,0,&sound);
  if (result != FMOD_OK)
  {
    errx(3,"Couldn't create DO2.wav sound");
  }
  samples[1] = sound; 
  result = FMOD_System_CreateSound(systemSound,"notes/DO3.wav",FMOD_CREATESAMPLE,0,&sound);
  if (result != FMOD_OK)
  {
    errx(3,"Couldn't create DO3.wav sound");
  }
  samples[2] = sound; 
  result = FMOD_System_CreateSound(systemSound,"notes/DO4.wav",FMOD_CREATESAMPLE,0,&sound);
  if (result != FMOD_OK)
  {
    errx(3,"Couldn't create DO4.wav sound");
  }
  samples[3] = sound; 


}