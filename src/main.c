
#include <stdlib.h>
#include <stdio.h>
#include "../headers/constantes.h"
#include "../headers/piano.h"
#include "../headers/widgets.h"
#include "../headers/sound.h"

void getBpm();
void getScale();
void getChords();
void getReps();
void initDefaultParameters(); 
void on_closeAboutDialog_clicked(); 
void on_chooseInstrument_changed();

void on_chooseInstrument_changed()
{
  actualInstrument = gtk_combo_box_get_active(GTK_COMBO_BOX(chooseInstrument));
  initAudio(); 
}

void initDefaultParameters()
{
  gtk_combo_box_set_active(chord1, LAMI); 
  gtk_combo_box_set_active(chord2, SOLMA); 
  gtk_combo_box_set_active(chord3, FAMA); 
  gtk_combo_box_set_active(chord4, MIMA); 

  gtk_combo_box_set_active(scaleComboBox, SOLMA);

  gtk_entry_set_text(repet1, "1"); 
  gtk_entry_set_text(repet2, "1"); 
  gtk_entry_set_text(repet3, "1"); 
  gtk_entry_set_text(repet4, "1"); 
  gtk_entry_set_text(bpmEntry, "100"); 
}

void on_MetronomeButton_toggled()
{
  if (song.metronome == 1)
  {
    NewChordPlaying = 0; 
    metroPlaying = 0; 
  }
  song.metronome *= -1;
}

// Fonction du bouton start
void startButtonClicked()
{  
  if (!playing)
  {
    initFileText(); 
    getBpm();
    getChords();
    getScale();
    getReps();
    playing = 1;
    metroPlaying=0;
    if (pthread_create(&metro, NULL, &metronome, NULL))
    {
      errx(1, "Failed to launch metronome");
    }
    if (pthread_create(&left, NULL, &leftHand, NULL))
    {
      errx(1, "Failed to launch left hand");
    }
    
    if (pthread_create(&right, NULL, &rightHand, NULL))
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
    
    if (song.scale != -1 && pthread_cancel(right))
    {
      errx(1, "Failed to close right hand");
    }
    playing = 0;
    fclose(fp); 
  }
  for (int i = 0; i < 48; i++)
  {
    gtk_widget_set_opacity(highlightsNotes[i], 0); 
  }
}


// Fonction du bouton About
void aboutButtonClicked()
{
  gtk_widget_show(GTK_WIDGET(AboutWindow));
  
}

void on_closeAboutDialog_clicked()
{
  gtk_widget_hide(GTK_WIDGET(AboutWindow));
}

// Fonction qui r??cup??re le BPM
void getBpm()
{
  char *endptr;
  const char *entry = gtk_entry_get_text(bpmEntry);
  errno = 0;
  song.bpm = (int)strtol(entry, &endptr, 10);

  if (entry == endptr || '\0' != *endptr || ERANGE == errno || song.bpm < 50 || song.bpm > 150 || (errno != 0 && song.bpm == 0))
    song.bpm = 100;
}

// Fonction qui r??cup??re les accords
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

void getReps() 
{
  song.repets[0] = atoi(gtk_entry_get_text(repet1));
  song.repets[1] = atoi(gtk_entry_get_text(repet2));
  song.repets[2] = atoi(gtk_entry_get_text(repet3));
  song.repets[3] = atoi(gtk_entry_get_text(repet4));
  song.repets[4] = atoi(gtk_entry_get_text(repet5));
  song.repets[5] = atoi(gtk_entry_get_text(repet6));
  song.repets[6] = atoi(gtk_entry_get_text(repet7));
  song.repets[7] = atoi(gtk_entry_get_text(repet8));
}

// Fonction qui r??cup??re la gamme
void getScale()
{
  song.scale = gtk_combo_box_get_active(scaleComboBox); 
}

int main()
{
  // Initialisation de GTK et ouverture de l'interface
  gtk_init(NULL, NULL);
  GtkBuilder* builder = gtk_builder_new_from_file("assets/interface.glade");
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
  repet1 = GTK_ENTRY(gtk_builder_get_object(builder,"repet1"));
  repet2 = GTK_ENTRY(gtk_builder_get_object(builder,"repet2"));
  repet3 = GTK_ENTRY(gtk_builder_get_object(builder,"repet3"));
  repet4 = GTK_ENTRY(gtk_builder_get_object(builder,"repet4"));
  repet5 = GTK_ENTRY(gtk_builder_get_object(builder,"repet5"));
  repet6 = GTK_ENTRY(gtk_builder_get_object(builder,"repet6"));
  repet7 = GTK_ENTRY(gtk_builder_get_object(builder,"repet7"));
  repet8 = GTK_ENTRY(gtk_builder_get_object(builder,"repet8"));
  AboutWindow =GTK_ABOUT_DIALOG(gtk_builder_get_object(builder,"GtkAboutDialog"));
  MetronomeButton = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "MetronomeButton")); 
  chooseInstrument = GTK_COMBO_BOX_TEXT(gtk_builder_get_object(builder, "chooseInstrument"));

  initDefaultParameters(); 
  // Personnalisation de la fen??tre
  gtk_window_set_title(GTK_WINDOW(window), "The Piano Partner");
  gtk_window_set_icon_from_file(GTK_WINDOW(window), "assets/icon.png", NULL);

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
  quitAudio();
  return 0; 
}
