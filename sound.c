#include "sound.h"

void getFrequency(int note, float* frequency, int* octave)
{//Fonction qui calcule le demi-ton à atteindre pour jouer la note souhaiter
  float douze = 1.05946;
  *octave = note/12;
  note = note % 12;
  *frequency = powf(douze, note);
}

void* playNoteSound(void* arguments)
{//Fonction executer qui calcule joue le son en utilisant la bibliotheque FMOD sans prendre en compte le bpm
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
  updateAudio();
  
  if (FMOD_Channel_SetVolume(channel,8.5) != FMOD_OK)
  {
	  errx(3,"Couldn't set the volume"); 
  }
  updateAudio();
  if (FMOD_Channel_SetFrequency(channel,44100*frequency) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  updateAudio();
  msleep(inter);
  pthread_exit(NULL);
}


void *playNoteSoundsec(void *arg)
{//Fonction executer qui calcule joue le son en utilisant la bibliotheque FMOD sans prendre en compte le bpm
  struct noteData *args = arg;
  int note = args->note;
  int inter =args->inter;
  float frequency;
  int octave;
  getFrequency(note, &frequency, &octave);
  FMOD_SOUND *son;
  son =samples[octave];
  printf("inter = %d",inter);
  float b =2.321/inter;
  float a =1/b;
  printf(" 1/b = %f \n",a);
  printf(" b = %f \n",b);
  FMOD_CHANNEL *channel;
  if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
  {
	  errx(3,"Couldn't play the sound");
  }
  updateAudio();
  
  if (FMOD_Channel_SetVolume(channel,8.5) != FMOD_OK)
  {
	  errx(3,"Couldn't set the volume"); 
  }
  updateAudio();
  if (FMOD_Channel_SetFrequency(channel,44100) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  updateAudio();

  if (FMOD_Channel_SetPitch(channel,b) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  updateAudio();
  if (FMOD_DSP_SetParameterFloat(dsp_effect,0,frequency*a) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't set the dsp float parametre");
  }
  updateAudio();
  if (FMOD_DSP_SetParameterFloat(dsp_effect,1,4096) != FMOD_OK)
  {
	  errx(3,"Signal analyse : couldn't set the dsp float parametre");
  }
  updateAudio();
  if (FMOD_Channel_AddDSP(channel,0,dsp_effect) != FMOD_OK)
  {
	  errx(3,"Couldn't add the DSP to the channel");
  }
  updateAudio();
  msleep(inter);
  pthread_exit(NULL);
  return NULL;
}

void initAudio()
{//Fonction qui va initialiser les systemes et les variables necessaires pour la lecture de son
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

void updateAudio()
{//Fonction qui update le system sonore
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
}