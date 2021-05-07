#include "piano.h"
#include "widgets.h"

// Algorithme de la main gauche
void* leftHand(void* arguments)
{
  struct songData *args = arguments;
  playChords(args->chords, args->repets, args->bpm);

  pthread_exit(NULL);
  return NULL;
}

// Algorithme de la main droite
/*void* rightHand(void* arguments)
{}*/

// Fonction qui teste les accords de Greensleeves
void* test()
{
  int myChords[8] = {LAMI, SOLMA, FAMA, MIMA, -1, -1, -1, -1};
  int repet[8] = {1, 1, 1, 1, 0, 0, 0, 0};
  
  playChords(myChords, repet, 100);
  
  pthread_exit(NULL);
  return NULL;
}

/*
void* test2(int note , int duree)
{
  struct noteData *test=malloc(sizeof(struct noteData));
  test->note =note;
  test->inter=duree;
  playNoteSoundsec(test);
  free(test);
  return NULL;
}*/

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
            playChord(usrChords[i], inter);
            msleep(inter);
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
  for (int i = 0; i <3; i++)
    gtk_widget_show(highlightsNotes[chords[chord][i]]); 
}

// Fonction qui joue une note
void playNote(int note, int inter)
{
  struct noteData * args=malloc(sizeof(struct noteData));
  args->note = note;
  args->inter = inter;
  pthread_t soundThr;
  pthread_t displayThr;
  
  if (pthread_create(&soundThr, NULL, &playNoteSound, (void*)args))
  {
    errx(1, "Failed to play note");
  }
  
  if (pthread_create(&displayThr, NULL, &displayNote, (void*)args))
  {
    errx(1, "Failed to display note");
  }
  
  pthread_detach(displayThr);  

  pthread_detach(soundThr);
  
}

// Fonction qui affiche une note
void* displayNote(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;
  int inter = args->inter;

  msleep(inter);
  gtk_widget_hide(highlightsNotes[note]); 
  pthread_exit(NULL);
}

/*
char* getChords()
{

}

char* getValueComboBox(GtkWidget* w)
{
  char[256] textentry;
  textentry = gtk_entry_get_text(GTK_ENTRY(w));
  return textentry;
}
*/