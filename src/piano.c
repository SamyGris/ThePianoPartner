#include "../headers/piano.h"

// Algorithme de la main gauche
void* leftHand()
{
  playChords(song.chords, song.repets, song.bpm);
  pthread_exit(NULL);
  return NULL;
}

// Algorithme de la main droite (sans patterns)
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
  int crotchet = 0;
  while(1)
  {
    int note;

    note = rand() % 5;
    if (note >= 3)
      note++;

    note = scaleNotes[scale][note] + 24;

    int length = getLength(&crotchet);
    
    float abs = (float)inter;
    abs *= powf(0.5, (double)length);
    gtk_widget_set_opacity(highlightsNotes[note], 1);
    char* noteLength = getLengthNote(length); 
    fprintf(fp, "       Note = %s, Durée = %s\n", notesString[note], noteLength); 
    playNote(note, abs);
    msleep(abs);
    gtk_widget_set_opacity(highlightsNotes[note], 0);
  }
  pthread_exit(NULL);
  return NULL;
}

// Choisit "aléatoirement" une durée pour la note
int getLength(int* crotchet)
{
  int length;
  if (!*crotchet)
    {
      int p = rand() % 100;
      if (p < 70)
        length = 2;
      else if (p < 80)
        length = 1;
      else if (p < 90)
      {
        length = 3;
        *crotchet = 2;
      }
      else if (p < 95)
      {
        length = 4;
        *crotchet = 3;
      }
      else
        length = 0;
    }
    else if (*crotchet >= 2)
    {
      if (rand() % 2)
      {
        length = 3;
        *crotchet-=2;
      }
      else
      {
        length = 4;
        *crotchet-=1;
      }
    }
    else
    {
      length = 4;
      *crotchet-=1;
    }

  return length;
}

// Algorithme jouant un metronome
void* metronome()
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
      if (pthread_create(&metrosound, NULL, &metrofunction, NULL))
      {
        errx(1, "Failed to launch metronome");
      }
      msleep(inter);
      metroPlaying += 1;
    }
    else
    {
      metroPlaying = 0;
    }
  }
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
  fprintf(fp, "\nAccord main gauche : %s\n   Main droite: \n", chordsString[chord]); 
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
