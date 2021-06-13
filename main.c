
#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "piano.h"
#include "widgets.h"
#include "sound.h"

void getBpm(void* arguments);
void getScale(void* arguments);
void getChords(void* arguments);


// Fonction du bouton start
void startButtonClicked()
{
  // VRAI ALGORITHME
  
  if (!playing)
  {
    struct songData *args=malloc(sizeof(struct songData));
    getBpm(args);
    getChords(args);
    playing = 1;

    if (pthread_create(&left, NULL, &leftHand, (void*)args))
    {
      errx(1, "Failed to launch left hand");
    }
    
    //getScale(&args);
    args->scale = LAMI;
    if (pthread_create(&right, NULL, &rightHand, (void*)args))
    {
      errx(1, "Failed to launch right hand");
    }
  }
}

// Fonction du bouton stop
void stopButtonClicked()
{
  if (playing)
  {
    if (pthread_cancel(left))
    {
      errx(1, "Failed to close left hand");
    }
    if (pthread_cancel(right))
    {
      errx(1, "Failed to close right hand");
    }
    playing = 0;
  }
}

// Fonction du bouton About
void aboutButtonClicked()
{}

// Fonction qui récupère le BPM
void getBpm(void* arguments)
{
  struct songData *args = arguments;
  char *endptr;
  const char *entry = gtk_entry_get_text(bpmEntry);
  errno = 0;
  args->bpm = (int)strtol(entry, &endptr, 10);

  if (entry == endptr || '\0' != *endptr || ERANGE == errno || args->bpm < 50 || args->bpm > 150 || (errno != 0 && args->bpm == 0))
    args->bpm = 100;
}

// Fonction qui récupère les accords
void getChords(void* arguments)
{
  struct songData *args = arguments;
  args->chords[0] = LAMI;
  args->chords[1] = SOLMA;
  args->chords[2] = FAMA;
  args->chords[3] = MIMA;
  args->chords[4] = -1;
  args->chords[5] = -1;
  args->chords[6] = -1;
  args->chords[7] = -1;
  args->repets[0] = 1;
  args->repets[1] = 1;
  args->repets[2] = 1;
  args->repets[3] = 1;
  args->repets[4] = 0;
  args->repets[5] = 0;
  args->repets[6] = 0;
  args->repets[7] = 0;
}

int main()
{
  // Initialisation de GTK et ouverture de l'interface
  gtk_init(NULL, NULL);
  GtkBuilder* builder = gtk_builder_new_from_file("assets/interface.glade");

  // Initialisation de tous les widgets de glade
  window = GTK_WIDGET(gtk_builder_get_object(builder, "interface"));
  startButton = GTK_BUTTON(gtk_builder_get_object(builder, "startButton"));
  stopButton = GTK_BUTTON(gtk_builder_get_object(builder, "stopButton"));
  aboutButton = GTK_BUTTON(gtk_builder_get_object(builder, "aboutButton"));
  bpmEntry = GTK_ENTRY(gtk_builder_get_object(builder, "bpmEntry"));
  scaleComboBox = GTK_COMBO_BOX(gtk_builder_get_object(builder, "scaleComboBox"));
  piano = GTK_WIDGET(gtk_builder_get_object(builder, "piano")); 

  // Personnalisation de la fenêtre
  gtk_window_set_title(GTK_WINDOW(window), "The Piano Partner");
  gtk_window_set_icon_from_file(GTK_WINDOW(window), "assets/icon.png", NULL);

  playing = 0;
  initConst();
  initAudio();


  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_builder_connect_signals(builder, NULL);
  gtk_widget_show((GtkWidget*)window);
  gtk_main();
  return 0; 
}