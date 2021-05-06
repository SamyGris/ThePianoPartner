
#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "piano.h"
#include "widgets.h"
#include "sound.h"

//Callbacks functions
void startButtonClicked()
{
  // LANCEMENT MAIN GAUCHE
  /*
  int bpm = getBpm();
  int scale = getScale();
  int[] chords = getChords();
  int[] repets = getRepets();
  stopped = 0;

  playChords(chords, repets, &stopped, bpm);
  */

  //TEST ACCORDS

  if (pthread_create(&left, NULL, &test, NULL))
  {
    errx(1, "Failed to launch left hand");
  }
}

void stopButtonClicked()
{
  /*
  if (pthread_cancel(left))
  {
    errx(1, "Failed to close left hand");
  }*/
}

void aboutButtonClicked()
{}

/*
int getBpm()
{
  char *endptr;
  char *entry = gtk_entry_get_text(bpmEntry);
  errno = 0;
  int bpm = (int)strtol(entry, &endptr, 10);

  if (entry == endptr || '\0' != *endptr || ERANGE == errno || bpm < 50 || bpm > 150) || (errno != 0 && bpm == 0))
    bpm = 100;

  return bpm;
}*/

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

  initConst();
  initAudio();
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_builder_connect_signals(builder, NULL);
  gtk_widget_show_all((GtkWidget*)window);
  gtk_main();
  return 0; 
}