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
  srand(time(NULL));

  while(1)
  {
    int note = rand() % 7;
    int length = rand() % 6;
    inter *= (int)pow(0.5, (double)length);
    playNote(scaleNotes[scale][note], inter);
  }
  pthread_exit(NULL);
  return NULL;
}

// Fonction qui teste les accords de Greensleeves
void* test()
{
  int myChords[8] = {LAMI, SOLMA, FAMA, MIMA, -1, -1, -1, -1};
  int repet[8] = {1, 1, 1, 1, 0, 0, 0, 0};
  
  playChords(myChords, repet, 250);
  
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

// Fonction qui affiche une note
void* displayNote(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;
  int inter = args->inter;
  gtk_widget_set_opacity(highlightsNotes[note], 1); 
  msleep(inter);
  gtk_widget_set_opacity(highlightsNotes[note], 0); 
  pthread_exit(NULL);
}


void getChords()
{
  song.chords[0] = gtk_combo_box_get_active(chord1); 
  song.chords[1] = gtk_combo_box_get_active(chord2); 
  song.chords[2] = gtk_combo_box_get_active(chord3); 
  song.chords[3] = gtk_combo_box_get_active(chord4); 
  song.chords[4] = gtk_combo_box_get_active(chord5); 
  song.chords[5] = gtk_combo_box_get_active(chord6); 
  song.chords[6] = gtk_combo_box_get_active(chord7); 
  song.chords[7] = gtk_combo_box_get_active(chord8); 
}

void getScale()
{
  song.scale = gtk_combo_box_get_active(scaleComboBox); 
}