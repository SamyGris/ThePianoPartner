#include "piano.h"

// Fonction qui orchestre la main gauche
void playChords(int usrChords[], int repet[], int* stopped, int bpm)
{
  int inter = 60000/bpm * 4;
  while (!*stopped)
  {
    for (int i = 0; i < 8; i++)
    {
      if (usrChords[i] != -1)
      {
        for (int j = 0; j < repet[i]; j++)
        {
          playChord(usrChords[i], inter);
          usleep(inter);
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
  struct noteData args;
  args.note = note;
  args.inter = inter;
  pthread_t thr;

  int e = pthread_create(&thr, NULL, &playNoteSound, (void*)&args);
  if (e)
  {
    errx(1, "Failed to play note");
  }

  e = pthread_create(&thr, NULL, &displayNote, (void*)&args);
  if (e)
  {
    errx(1, "Failed to display note");
  }
}

// Fonction qui teste les accords de Greensleeves
void test()
{
  /*int* stopped = malloc(sizeof(int));
  *stopped = 0;
  int myChords[8] = {LAMI, SOLMA, FAMA, MIMA, -1, -1, -1, -1};
  int repet[8] = {2, 2, 2, 2, 0, 0, 0, 0};
  
  playChords(myChords, repet, stopped, 100);*/
  /*struct noteData *samy=malloc(sizeof(struct noteData));
  samy->note=SI4;
  samy->inter=5;
  playNoteSound(samy);*/
  struct noteData *nail=malloc(sizeof(struct noteData));
  nail->note=FA3;
  nail->inter=5;
  displayNote(nail);
  playNoteSound(nail);

}

void* displayNote(void* arguments)
{
  struct noteData *args = arguments;
  int note = args->note;
  int inter = args->inter;


  GtkWidget* highlighter; 
  int x = position[note];
  int y = 1;


  if (note == DO1 || note == DO2 || note == DO3 || note == DO4 || 
  note == FA1 || note == FA2 || note == FA3 || note == FA4)
  {
    highlighter = gtk_image_new_from_file("assets/tiles/left.png");
  }
  else if (note == MI1 || note == MI2 || note == MI3 || note == MI4 ||
  note == SI1 || note == SI2 || note == SI3 || note == SI4)
  {
    highlighter = gtk_image_new_from_file("assets/tiles/right.png");
  }
  else if (note == RE1 || note == RE2 || note == RE3 || note == RE4 ||
  note == SOL1 || note == SOL2 || note == SOL3 || note == SOL4 ||
  note == LA1 || note == LA2 || note == LA3 || note == LA4)
  {
    y = 2; 
    highlighter = gtk_image_new_from_file("assets/tiles/center.png");
  }
  else
  {
    highlighter = gtk_image_new_from_file("assets/tiles/black.png");
  }

  gtk_widget_show(highlighter); 

  gtk_container_add(GTK_CONTAINER(piano), highlighter); 
  gtk_fixed_move(GTK_FIXED(piano), highlighter, x, y);
  usleep(inter); 
  gtk_widget_hide(highlighter); 

  pthread_exit(NULL);
  return NULL;
}
