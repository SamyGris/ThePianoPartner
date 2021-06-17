#include "../headers/sound.h"

// Fonction qui calcule le demi-ton à atteindre pour jouer la note souhaitée
void getDemitone(int note, float* demitone, int* octave)
{
  float demitonevalue = 1.05946;
  *octave = note/12;
  note = note % 12;
  *demitone = powf(demitonevalue, note);
}
// Fonction executée qui joue le son en fonction de la note
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
  if (FMOD_Channel_SetVolume(channel,volume) != FMOD_OK)
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
  msleep(7000);
  free(args);
  pthread_exit(NULL);
}
//Fonction qui joue le son du metronome
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
  volume=4;
  
  if (FMOD_System_Create(&systemSound) != FMOD_OK)
  {
    errx(3,"Couldn't create a system");
  }
  // Initialisation du système en mode lecture normale de son et à 64 channels en mode thread
  if (FMOD_System_Init(systemSound,64,FMOD_INIT_THREAD_UNSAFE,NULL) != FMOD_OK)
  {
    errx(3,"Couldn't init a system");
  }
  // Chargement de la banque sonore
  FMOD_SOUND *sound;

  for (int i=0 ; i<4 ; i++ )
  { 
        char ret [200] = "" ;
        char prefix[130] = "notes/" ;
        char end[50] = ".wav" ; 

        char x = actualInstrument + '0' ;

        char temp = i + '0' ;

        int res = 0 ; 
        for (int j = 0 ; j < 6 ; j++)
        {
            ret[j] = prefix[j] ; 
            res = j ; 
        }

        
          ret[res+1] = x ; 
          ret [res+2] = temp ; 
        strcat(ret,end) ; 
        if (ret[6] == '1'||ret[6]=='2'||ret[6]=='3' ) 
        {
            volume =0.5 ;
        } 
        FMOD_System_CreateSound(systemSound,ret,FMOD_CREATESAMPLE,0,&sound) ;
        samples[i] = sound;
  }

  if (FMOD_System_CreateSound(systemSound,"metronome/bim.wav",FMOD_CREATESAMPLE,0, &sound) != FMOD_OK)
  {
    errx(3,"Couldn't create bim.wav sound");
  }
  metronomeSounds[0]=sound;
  if (FMOD_System_CreateSound(systemSound,"metronome/bam.wav",FMOD_CREATESAMPLE,0, &sound) != FMOD_OK)
  {
    errx(3,"Couldn't create bam.wav sound");
  }
  metronomeSounds[1]=sound;
}

// Fonction qui actualise le système audio
void updateAudio()
{
  if (FMOD_System_Update(systemSound)!=FMOD_OK)
  {
    errx(3,"error during system update");
  }
}
// Fonction qui libére les sons utilisé et le system et le quitte
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