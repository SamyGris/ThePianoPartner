#include "piano.h"
#include "widgets.h"

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
  int pat = 0;
  while(1)
  {
    int note;

    if (rand() % 2)
    {
      note = rand() % 5;
      if (note >= 3)
        note++;
    }
    else
      note = rand() % 7;

    note = scaleNotes[scale][note] + 24;
    if (i==0)
    {
      pat = rand() % 2;
    }

    int length = patterns[pat][i];
    
    float abs = (float)inter;
    abs *= powf(0.5, (double)length);
    gtk_widget_set_opacity(highlightsNotes[note], 1);
    playNote(note, abs);
    msleep(abs);
    gtk_widget_set_opacity(highlightsNotes[note], 0);
    do
    {
      i++;
      i = i%16;
    } while (i < 16 && patterns[pat][i] == -1);
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