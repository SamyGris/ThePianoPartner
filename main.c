
#include <stdlib.h>
#include <stdio.h>
#include "constantes.h"
#include "piano.h"
#include "widgets.h"
#include "sound.h"

void getBpm();
void getScale();
void getChords();


// Fonction du bouton start
void startButtonClicked()
{
  getChords(); 
  getScale();
  
  // VRAI ALGORITHME
  if (!playing)
  {
    getBpm();
    getChords();
    getScale();
    playing = 1;

    if (pthread_create(&left, NULL, &leftHand, NULL))
    {
      errx(1, "Failed to launch left hand");
    }
    /*
    if (pthread_create(&right, NULL, &rightHand, NULL))
    {
      errx(1, "Failed to launch right hand");
    }*/
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
  for (int i = 0; i < 48; i++)
  {
    gtk_widget_set_opacity(highlightsNotes[i], 0); 
  }
}

// Fonction du bouton About
void aboutButtonClicked()
{}

// Fonction qui récupère le BPM
void getBpm()
{
  char *endptr;
  const char *entry = gtk_entry_get_text(bpmEntry);
  errno = 0;
  song.bpm = (int)strtol(entry, &endptr, 10);

  if (entry == endptr || '\0' != *endptr || ERANGE == errno || song.bpm < 50 || song.bpm > 150 || (errno != 0 && song.bpm == 0))
    song.bpm = 100;
}

// Fonction qui récupère les accords
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

// Fonction qui récupère la gamme
void getScale()
{
  song.scale = gtk_combo_box_get_active(scaleComboBox); 
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
  chord1 =  GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord1")); 
  chord2 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord2")); 
  chord3 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord3")); 
  chord4 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord4")); 
  chord5 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord5")); 
  chord6 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord6")); 
  chord7 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord7")); 
  chord8 = GTK_COMBO_BOX(gtk_builder_get_object(builder, "chord8")); 

  // Personnalisation de la fenêtre
  gtk_window_set_title(GTK_WINDOW(window), "The Piano Partner");
  gtk_window_set_icon_from_file(GTK_WINDOW(window), "assets/icon.png", NULL);

  playing = 0;
  initConst();
  initAudio();
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_builder_connect_signals(builder, NULL);
  gtk_widget_show_all((GtkWidget*)window);
  for (int i = 0; i < 48; i++)
  {
    gtk_widget_set_opacity(highlightsNotes[i], 0); 
  }
  gtk_main();
  return 0; 
}