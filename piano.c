#include "piano.h"
#include "widgets.h"



// Algorithme jouant un metronome
void *metronome()
{
  int inter = 60000/(song.bpm);
  while(playing)
  {
    printf("%s","");
    if(song.metronome == 1)
    {
      if (!NewChordPlaying)
      {
        NewChordPlaying = 1;  
      }
      while(NewChordPlaying != 2)
      {
        printf("%s",""); 
        continue; 
      }
      pthread_t metrosound;
      if (pthread_create(&metrosound, NULL, &bim, NULL))
      {
        errx(1, "Failed to launch metronome");
      }
      msleep(inter);
    }
  }
  return NULL; 
}

void *bim()
{
  FMOD_CHANNEL *channel;
  FMOD_SOUND *sound;
  if (FMOD_System_CreateSound(systemSound,"metronome/bam.wav",FMOD_CREATESAMPLE,0, &sound) != FMOD_OK)
  {
    errx(3,"Couldn't create BIM.wav sound");
  }
  if (FMOD_System_PlaySound(systemSound,sound,NULL,0,&channel) != FMOD_OK)
  {
	  errx(3,"Couldn't play the metronome");
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

// Algorithme de la main gauche
void* leftHand()
{
  playChords(song.chords, song.repets, song.bpm);
  pthread_exit(NULL);
  return NULL;
}

// Algorithme de la main droite
void* rightHand()
{
  int inter = 60000/(song.bpm)*4;
  int scale = song.scale;
  if (song.scale == -1)
  {
    pthread_exit(NULL);
    return NULL;
  }
  srand(time(NULL));
  int i = 0;
  while(1)
  {
    /* GAMME NON PENTATONIQUE
    int note = rand() % 7;*/
    int note = rand() % 5;
    if (note >= 3)
      note++;
    note = scaleNotes[scale][note] + 24;

    //int length = rand() % 6;
    //int length = 2;
    int length = patterns[0][i];
    if (length != -1)
    {
      float abs = (float)inter;
      abs *= powf(0.5, (double)length);
      gtk_widget_set_opacity(highlightsNotes[note], 1);
      playNote(note, abs);
      msleep(abs);
      gtk_widget_set_opacity(highlightsNotes[note], 0);
    }
    i = (i+1)%4;
  }
  pthread_exit(NULL);
  return NULL;
}

// Fonction qui joue les différents accords de la main gauche
void playChords(int usrChords[], int repet[], int bpm)
{
  int inter = 60000/bpm * 4;
  while (1)
  {
    for (int i = 0; i < 8; i++)
      {
        if (usrChords[i] != -1 && repet[i] > 0)
        {
          for (int j = 0; j < repet[i]; j++)
          {
            for (int k = 0; k < 3; k++)
              gtk_widget_set_opacity(highlightsNotes[chords[usrChords[i]][k]], 1);
            playChord(usrChords[i], inter);
            msleep(inter);
            for (int k = 0; k < 3; k++)
              gtk_widget_set_opacity(highlightsNotes[chords[usrChords[i]][k]], 0);
          }
        }
    }
  }
}

// Fonction qui joue un accord
void playChord(int chord, int inter)
{
  if (NewChordPlaying == 1)
  {
    NewChordPlaying = 2; 
  }
  for (int i = 0; i < 3; i++)
  {
    playNote(chords[chord][i], inter);
  }
}

// Fonction qui joue une note
void playNote(int note, int inter)
{
  struct noteData * args=malloc(sizeof(struct noteData));
  args->note = note;
  args->inter = inter;
  pthread_t soundThr;
  
  if (pthread_create(&soundThr, NULL, &playNoteSound, (void*)args))
  {
    errx(1, "Failed to play note");
  } 
}