#include "sound.h"

void getFrequency(int note, float* frequency, int* octave)
{
  float douze = 1.05946;
  *octave = note/12;
  note = note % 12;
  *frequency = powf(douze, note);
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
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  
  if (FMOD_Channel_SetVolume(channel,7.5) != FMOD_OK)
  {
	  errx(3,"Couldn't set the volume"); 
  }
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  if (FMOD_Channel_SetFrequency(channel,44100) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  if (FMOD_Channel_SetPitch(channel,frequency) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
    
  msleep(inter);
  pthread_exit(NULL);
    if (FMOD_Sound_Release(son) != FMOD_OK)
  {
    errx(3, "Couldn't release the sound");
  }
    if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  return NULL;
}

/*
void *playNoteSoundsec(void *arg)
{
  struct noteData *args = arg;
  int note = args->note;
  int inter =args->inter;
  float frequency;
  int octave;

  getFrequency(note, &frequency, &octave);

  son =samples[octave];
  float b =2321/inter;
  float a =1/b;
  FMOD_CHANNEL *channel;
  if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
  {
	  errx(3,"Couldn't play the sound");
  }
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  
  if (FMOD_Channel_SetVolume(channel,7.5) != FMOD_OK)
  {
	  errx(3,"Couldn't set the volume"); 
  }
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  if (FMOD_Channel_SetFrequency(channel,44100*a*frequency) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  
    if (FMOD_DSP_SetParameterFloat(dsp_effect,0,b) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't set the dsp float parametre");
  }

  if (FMOD_Channel_AddDSP(channel,0,dsp_effect) != FMOD_OK)
  {
	  errx(3,"Couldn't add the DSP to the channel");
  }
  msleep(inter);
  pthread_exit(NULL);
    if (FMOD_Sound_Release(son) != FMOD_OK)
  {
    errx(3, "Couldn't release the sound");
  }
    if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
  return NULL;
  
}*/

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

  if (FMOD_System_CreateDSPByType(systemSound,FMOD_DSP_TYPE_PITCHSHIFT,&dsp_effect) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't create a dsp ");
  }
}