#include "sound.h"

// Fonction qui calcule le demi-ton à atteindre pour jouer la note souhaitée
void getDemitone(int note, float* demitone, int* octave)
{
  float demitonevalue = 1.05946;
  *octave = note/12;
  note = note % 12;
  *demitone = powf(demitonevalue, note);
}

// Fonction executée qui joue le son en utilisant la bibliothèque FMOD sans prendre en compte le BPM
void* playNoteSound(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;
  float demitone;
  int octave;
  FMOD_SOUND *son;
  getDemitone(note, &demitone, &octave);
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
  float initial_frequency;
  if (FMOD_Channel_GetFrequency(channel,&initial_frequency) != FMOD_OK)
  {
	  errx(3,"Couldn't get the frequency");
  }
  updateAudio();
  if (FMOD_Channel_SetFrequency(channel,initial_frequency*demitone) != FMOD_OK)
  {
	  errx(3,"Couldn't set the frequency");
  }
  updateAudio();
  // Ici on laisse la note durer le temps qu'il lui faut (2321 ms)
  // A faire : ajouter les enums pour la durée de chaque note
  msleep(2321);
  pthread_exit(NULL);
}

// Fonction qui joue le son en utilisant la bibliothèque FMOD en prenant en compte le bpm
void *playNoteSoundsec(void *arg)
{
  struct noteData *args = arg;
  int note = args->note;
  int inter =args->inter;
  float demiTone;
  int octave;
  getDemitone(note, &demiTone, &octave);
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
  if (FMOD_DSP_SetParameterFloat(dsp_effect,0,demiTone*a) != FMOD_OK)
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
  msleep(2321);
  pthread_exit(NULL);
  return NULL;
}

// Fonction qui va initialiser le système et les variables nécessaires pour la lecture du son
void initAudio()
{
  // Initialisation et création de notre système    
  if (FMOD_System_Create(&systemSound) != FMOD_OK)
  {
    errx(3,"Couldn't create a system");
  }
  // Initialisation du système en mode lecture normale de son et à 32 channels
  if (FMOD_System_Init(systemSound,64,FMOD_INIT_NORMAL,NULL) != FMOD_OK)
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

// Fonction qui update le système sonore
void updateAudio()
{
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
}