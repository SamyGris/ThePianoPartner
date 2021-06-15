#include "../headers/sound.h"

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
  getDemitone(note, &demitone, &octave);
  son = samples[octave];  
  FMOD_CHANNEL *channel;
  if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
  {
	  errx(3,"Couldn't play the sound");
  }
  updateAudio();
  if (FMOD_Channel_SetVolume(channel,4) != FMOD_OK)
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
  msleep(4000);
  free(args);
  pthread_exit(NULL);
}

// Fonction qui joue le son en utilisant la bibliothèque FMOD en prenant en compte le bpm
void playNoteSoundSec(int note, int inter)
{
  float demiTone;
  int octave;
  getDemitone(note, &demiTone, &octave);
  son =samples[octave];
  float b = 2.321/inter;
  float a = 1/b;
  FMOD_CHANNEL *channel;
  if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
  {
	  errx(3,"Couldn't play the sound");
  }
  updateAudio();
  
  if (FMOD_Channel_SetVolume(channel,4) != FMOD_OK)
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
  msleep(4000);
}
void *metrofunction()
{
  FMOD_CHANNEL *channel;
  if (metroPlaying%4==0)
  {
    son=metronomeSounds[0];
    if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
    {
	    errx(3,"Couldn't play the metronome");
    }
  }
  else
  {
    son=metronomeSounds[1];
    if (FMOD_System_PlaySound(systemSound,son,NULL,0,&channel) != FMOD_OK)
    {
	    errx(3,"Couldn't play the metronome");
    }
  }
  updateAudio();
  if (FMOD_Channel_SetVolume(channel,8.5) != FMOD_OK)
  {
	  errx(3,"Couldn't set the volume"); 
  }
  updateAudio();
  msleep(4000);
  pthread_exit(NULL);
}
// Fonction qui va initialiser le système et les variables nécessaires pour la lecture du son
void initAudio()
{
  // Initialisation des valeurs pour le métronome et pour le début de jeu du piano
  song.metronome = -1; 
  NewChordPlaying = 0; 
  metroPlaying=0;
  playing=0;
  // Initialisation et création de notre système    
  if (FMOD_System_Create(&systemSound) != FMOD_OK)
  {
    errx(3,"Couldn't create a system");
  }
  // Initialisation du système en mode lecture normale de son et à 32 channels
  if (FMOD_System_Init(systemSound,64,FMOD_INIT_THREAD_UNSAFE,NULL) != FMOD_OK)
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
  if (FMOD_System_CreateSound(systemSound,"metronome/bim.wav",FMOD_CREATESAMPLE,0, &sound) != FMOD_OK)
  {
    errx(3,"Couldn't create BIM.wav sound");
  }
  metronomeSounds[0]=sound;
  if (FMOD_System_CreateSound(systemSound,"metronome/bam.wav",FMOD_CREATESAMPLE,0, &sound) != FMOD_OK)
  {
    errx(3,"Couldn't create BIM.wav sound");
  }
  metronomeSounds[1]=sound;
}

// Fonction qui update le système sonore
void updateAudio()
{
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
}
// Fonction qui quitte le système audio
void quitAudio()
{
  if (son !=NULL)
  {
      if (FMOD_Sound_Release(son)!=FMOD_OK)
    {
      errx(1,"Eroor while releasing sound");
    }
  }
  if (FMOD_System_Close(systemSound)!=FMOD_OK)
  {
    errx(1,"Eroor while closing the system");
  }
  if (FMOD_System_Release(systemSound)!=FMOD_OK)
  {
    errx(1,"Eroor while releasing sytem");
  }
}