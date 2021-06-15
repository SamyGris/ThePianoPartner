#include "constantes.h"
#include "widgets.h"
#include "toolbox.h"
#include <gtk/gtk.h>

void initConst()
{
  // Gammes majeures

  scaleNotes[DOMA][0] = DO1;
  scaleNotes[DOMA][1] = RE1;
  scaleNotes[DOMA][2] = MI1;
  scaleNotes[DOMA][3] = FA1;
  scaleNotes[DOMA][4] = SOL1;
  scaleNotes[DOMA][5] = LA1;
  scaleNotes[DOMA][6] = SI1;

  scaleNotes[REMA][0] = RE1;
  scaleNotes[REMA][1] = MI1;
  scaleNotes[REMA][2] = FAD1;
  scaleNotes[REMA][3] = SOL1;
  scaleNotes[REMA][4] = LA1;
  scaleNotes[REMA][5] = SI1;
  scaleNotes[REMA][6] = DOD1;

  scaleNotes[MIMA][0] = MI1;
  scaleNotes[MIMA][1] = FAD1;
  scaleNotes[MIMA][2] = SOLD1;
  scaleNotes[MIMA][3] = LA1;
  scaleNotes[MIMA][4] = SI1;
  scaleNotes[MIMA][5] = DOD2;
  scaleNotes[MIMA][6] = RED2;

  scaleNotes[FAMA][0] = RE2;
  scaleNotes[FAMA][1] = MI2;
  scaleNotes[FAMA][2] = FAD2;
  scaleNotes[FAMA][3] = SOL2;
  scaleNotes[FAMA][4] = LA2;
  scaleNotes[FAMA][5] = SI2;
  scaleNotes[FAMA][6] = DOD2;

  scaleNotes[SOLMA][0] = SOL1;
  scaleNotes[SOLMA][1] = LA1;
  scaleNotes[SOLMA][2] = SI1;
  scaleNotes[SOLMA][3] = DO2;
  scaleNotes[SOLMA][4] = RE2;
  scaleNotes[SOLMA][5] = MI2;
  scaleNotes[SOLMA][6] = FAD2;

  scaleNotes[LAMA][0] = LA1;
  scaleNotes[LAMA][1] = SI1;
  scaleNotes[LAMA][2] = DOD2;
  scaleNotes[LAMA][3] = RE2;
  scaleNotes[LAMA][4] = MI2;
  scaleNotes[LAMA][5] = FAD2;
  scaleNotes[LAMA][6] = SOLD2;

  scaleNotes[SIMA][0] = SI1;
  scaleNotes[SIMA][1] = DOD2;
  scaleNotes[SIMA][2] = RED2;
  scaleNotes[SIMA][3] = MI2;
  scaleNotes[SIMA][4] = FAD2;
  scaleNotes[SIMA][5] = SOLD2;
  scaleNotes[SIMA][6] = LAD2;

  scaleNotes[DODMA][0] = DOD1;
  scaleNotes[DODMA][1] = RED1;
  scaleNotes[DODMA][2] = FA1;
  scaleNotes[DODMA][3] = FAD1;
  scaleNotes[DODMA][4] = SOLD1;
  scaleNotes[DODMA][5] = LAD1;
  scaleNotes[DODMA][6] = DO2;

  scaleNotes[REDMA][0] = RED1;
  scaleNotes[REDMA][1] = FA1;
  scaleNotes[REDMA][2] = SOL1;
  scaleNotes[REDMA][3] = SOLD1;
  scaleNotes[REDMA][4] = LA2;
  scaleNotes[REDMA][5] = SI2;
  scaleNotes[REDMA][6] = DOD2;

  scaleNotes[FADMA][0] = FAD1;
  scaleNotes[FADMA][1] = SOLD1;
  scaleNotes[FADMA][2] = LAD1;
  scaleNotes[FADMA][3] = SI1;
  scaleNotes[FADMA][4] = DOD2;
  scaleNotes[FADMA][5] = RED2;
  scaleNotes[FADMA][6] = FA2;

  scaleNotes[SOLDMA][0] = SOLD1;
  scaleNotes[SOLDMA][1] = LAD1;
  scaleNotes[SOLDMA][2] = DO2;
  scaleNotes[SOLDMA][3] = DOD2;
  scaleNotes[SOLDMA][4] = RED2;
  scaleNotes[SOLDMA][5] = FA2;
  scaleNotes[SOLDMA][6] = SOL2;

  scaleNotes[LADMA][0] = LAD1;
  scaleNotes[LADMA][1] = DO2;
  scaleNotes[LADMA][2] = RE2;
  scaleNotes[LADMA][3] = RED2;
  scaleNotes[LADMA][4] = FA2;
  scaleNotes[LADMA][5] = SOL2;
  scaleNotes[LADMA][6] = LA2;

  // Gammes mineures

  scaleNotes[DOMI][0] = DO1;
  scaleNotes[DOMI][1] = RE1;
  scaleNotes[DOMI][2] = RED1;
  scaleNotes[DOMI][3] = FA1;
  scaleNotes[DOMI][4] = SOL1;
  scaleNotes[DOMI][5] = SOLD1;
  scaleNotes[DOMI][6] = LAD1;

  scaleNotes[REMI][0] = RE1;
  scaleNotes[REMI][1] = MI1;
  scaleNotes[REMI][2] = FA1;
  scaleNotes[REMI][3] = SOL1;
  scaleNotes[REMI][4] = LA1;
  scaleNotes[REMI][5] = LAD1;
  scaleNotes[REMI][6] = DO1;

  scaleNotes[MIMI][0] = MI1;
  scaleNotes[MIMI][1] = FAD1;
  scaleNotes[MIMI][2] = SOL1;
  scaleNotes[MIMI][3] = LA1;
  scaleNotes[MIMI][4] = SI1;
  scaleNotes[MIMI][5] = DO2;
  scaleNotes[MIMI][6] = RE2;

  scaleNotes[FAMI][0] = FA1;
  scaleNotes[FAMI][1] = SOL1;
  scaleNotes[FAMI][2] = SOLD1;
  scaleNotes[FAMI][3] = LAD2;
  scaleNotes[FAMI][4] = DO2;
  scaleNotes[FAMI][5] = DOD2;
  scaleNotes[FAMI][6] = RED2;

  scaleNotes[SOLMI][0] = SOL1;
  scaleNotes[SOLMI][1] = LA1;
  scaleNotes[SOLMI][2] = LAD1;
  scaleNotes[SOLMI][3] = DO2;
  scaleNotes[SOLMI][4] = RE2;
  scaleNotes[SOLMI][5] = RED2;
  scaleNotes[SOLMI][6] = FA2;

  scaleNotes[LAMI][0] = LA1;
  scaleNotes[LAMI][1] = SI1;
  scaleNotes[LAMI][2] = DO2;
  scaleNotes[LAMI][3] = RE2;
  scaleNotes[LAMI][4] = MI2;
  scaleNotes[LAMI][5] = FA2;
  scaleNotes[LAMI][6] = SOL2;

  scaleNotes[SIMI][0] = SI1;
  scaleNotes[SIMI][1] = DOD2;
  scaleNotes[SIMI][2] = RE2;
  scaleNotes[SIMI][3] = MI2;
  scaleNotes[SIMI][4] = FAD2;
  scaleNotes[SIMI][5] = SOL2;
  scaleNotes[SIMI][6] = LA2;

  scaleNotes[DODMI][0] = DOD1;
  scaleNotes[DODMI][1] = RED1;
  scaleNotes[DODMI][2] = MI1;
  scaleNotes[DODMI][3] = FAD1;
  scaleNotes[DODMI][4] = SOLD1;
  scaleNotes[DODMI][5] = LA1;
  scaleNotes[DODMI][6] = SI1;

  scaleNotes[REDMI][0] = RED1;
  scaleNotes[REDMI][1] = FA1;
  scaleNotes[REDMI][2] = LAD1;
  scaleNotes[REDMI][3] = SOLD1;
  scaleNotes[REDMI][4] = LAD1;
  scaleNotes[REDMI][5] = SI1;
  scaleNotes[REDMI][6] = DOD2;

  scaleNotes[FADMI][0] = FAD1;
  scaleNotes[FADMI][1] = SOLD1;
  scaleNotes[FADMI][2] = LA1;
  scaleNotes[FADMI][3] = SI1;
  scaleNotes[FADMI][4] = DOD2;
  scaleNotes[FADMI][5] = RE2;
  scaleNotes[FADMI][6] = MI2;

  scaleNotes[SOLDMI][0] = SOLD1;
  scaleNotes[SOLDMI][1] = LAD1;
  scaleNotes[SOLDMI][2] = SI1;
  scaleNotes[SOLDMI][3] = DOD2;
  scaleNotes[SOLDMI][4] = RED2;
  scaleNotes[SOLDMI][5] = MI2;
  scaleNotes[SOLDMI][6] = FAD2;

  scaleNotes[LADMI][0] = LAD1;
  scaleNotes[LADMI][1] = DO2;
  scaleNotes[LADMI][2] = DOD2;
  scaleNotes[LADMI][3] = RED2;
  scaleNotes[LADMI][4] = FA2;
  scaleNotes[LADMI][5] = FAD2;
  scaleNotes[LADMI][6] = SOLD2;

  // Accords majeurs

  chords[DOMA][0] = DO1;
  chords[DOMA][1] = MI1;
  chords[DOMA][2] = SOL1;

  chords[REMA][0] = RE1;
  chords[REMA][1] = FAD1;
  chords[REMA][2] = LA1;

  chords[MIMA][0] = MI1;
  chords[MIMA][1] = SOLD1;
  chords[MIMA][2] = SI1;

  chords[FAMA][0] = FA1;
  chords[FAMA][1] = LA1;
  chords[FAMA][2] = DO2;

  chords[SOLMA][0] = SOL1;
  chords[SOLMA][1] = SI1;
  chords[SOLMA][2] = RE2;

  chords[LAMA][0] = LA1;
  chords[LAMA][1] = DOD2;
  chords[LAMA][2] = MI2;

  chords[SIMA][0] = SI1;
  chords[SIMA][1] = RED2;
  chords[SIMA][2] = FAD2;

  chords[DODMA][0] = DOD1; 
  chords[DODMA][1] = FA1; 
  chords[DODMA][2] = SOLD1;

  chords[REDMA][0] = RED1; 
  chords[REDMA][1] = SOL1; 
  chords[REDMA][2] = LAD1; 

  chords[FADMA][0] = FAD1; 
  chords[FADMA][1] = LAD1; 
  chords[FADMA][2] = DOD2; 

  chords[SOLDMA][0] = SOLD1; 
  chords[SOLDMA][1] = DO2; 
  chords[SOLDMA][2] = RED2; 

  chords[LADMA][0] = LAD1; 
  chords[LADMA][1] = RE2; 
  chords[LADMA][2] = FA2; 



  // Accords mineurs

  chords[DOMI][0] = DO1;
  chords[DOMI][1] = RED1;
  chords[DOMI][2] = SOL1;

  chords[REMI][0] = RE1;
  chords[REMI][1] = FA1;
  chords[REMI][2] = LA1;

  chords[MIMI][0] = MI1;
  chords[MIMI][1] = SOL1;
  chords[MIMI][2] = SI1;

  chords[FAMI][0] = FA1;
  chords[FAMI][1] = SOLD1;
  chords[FAMI][2] = DO2;

  chords[SOLMI][0] = SOL1;
  chords[SOLMI][1] = LAD1;
  chords[SOLMI][2] = RE2;

  chords[LAMI][0] = LA1;
  chords[LAMI][1] = DO2;
  chords[LAMI][2] = MI2;

  chords[SIMI][0] = SI1;
  chords[SIMI][1] = RE2;
  chords[SIMI][2] = FAD2;

  chords[DODMI][0] = DOD1; 
  chords[DODMI][1] = MI1; 
  chords[DODMI][2] = SOLD1;

  chords[REDMI][0] = RED1; 
  chords[REDMI][1] = FAD1; 
  chords[REDMI][2] = LAD1; 

  chords[FADMI][0] = FAD1; 
  chords[FADMI][1] = LA1; 
  chords[FADMI][2] = DOD2; 

  chords[SOLDMI][0] = SOLD1; 
  chords[SOLDMI][1] = SI1; 
  chords[SOLDMI][2] = RED2; 

  chords[LADMI][0] = LAD1; 
  chords[LADMI][1] = DOD2; 
  chords[LADMI][2] = FA2; 

  //position des touches sur l'écran (en px)

  position[DO1] = 11; 
  position[DO2] = 139; 
  position[DO3] = 266; 
  position[DO4] = 393; 

  position[RE1] = 31; 
  position[RE2] = 158; 
  position[RE3] = 286; 
  position[RE4] = 413; 

  position[MI1] = 47; 
  position[MI2] = 175; 
  position[MI3] = 303; 
  position[MI4] = 430; 

  position[FA1] = 65; 
  position[FA2] = 193; 
  position[FA3] = 321;
  position[FA4] = 448;

  position[SOL1] = 85; 
  position[SOL2] = 213; 
  position[SOL3] = 340; 
  position[SOL4] = 467; 

  position[LA1] = 104; 
  position[LA2] = 231; 
  position[LA3] = 358; 
  position[LA4] = 485; 

  position[SI1] = 121; 
  position[SI2] = 248;
  position[SI3] = 375;
  position[SI4] = 501; 

  position[DOD1] = 26; 
  position[DOD2] = 153; 
  position[DOD3] = 280; 
  position[DOD4] = 408; 

  position[RED1] = 44; 
  position[RED2] = 171; 
  position[RED3] = 298; 
  position[RED4] = 426; 

  position[FAD1] = 80; 
  position[FAD2] = 207; 
  position[FAD3] = 335; 
  position[FAD4] = 462; 

  position[SOLD1] = 98; 
  position[SOLD2] = 225; 
  position[SOLD3] = 353;
  position[SOLD4] = 480; 

  position[LAD1] = 116; 
  position[LAD2] = 243; 
  position[LAD3] = 371; 
  position[LAD4] = 498;

  // Initialisation des patterns
  
  patterns[0][0] = 2;
  patterns[0][1] = -1;
  patterns[0][2] = -1;
  patterns[0][3] = -1;

  patterns[0][4] = 3;
  patterns[0][5] = -1;
  patterns[0][6] = 3;
  patterns[0][7] = -1;

  patterns[0][8] = 2;
  patterns[0][9] = -1;
  patterns[0][10] = -1;
  patterns[0][11] = -1;

  patterns[0][12] = 3;
  patterns[0][13] = -1;
  patterns[0][14] = 3;
  patterns[0][15] = -1;

  patterns[1][0] = 3;
  patterns[1][1] = -1;
  patterns[1][2] = 3;
  patterns[1][3] = -1;

  patterns[1][4] = 3;
  patterns[1][5] = -1;
  patterns[1][6] = 4;
  patterns[1][7] = 4;

  patterns[1][8] = 3;
  patterns[1][9] = -1;
  patterns[1][10] = 3;
  patterns[1][11] = -1;

  patterns[1][12] = 4;
  patterns[1][13] = 4;
  patterns[1][14] = 3;
  patterns[1][15] = -1;


  for (int note = 0; note < 48; note++)
  {
    int x = position[note];
    int y = 1;
    if (note == DO1 || note == DO2 || note == DO3 || note == DO4 || 
    note == FA1 || note == FA2 || note == FA3 || note == FA4)
    {
      highlightsNotes[note] = gtk_image_new_from_file("assets/tiles/left.png");
    }
    else if (note == MI1 || note == MI2 || note == MI3 || note == MI4 ||
    note == SI1 || note == SI2 || note == SI3 || note == SI4)
    {
      highlightsNotes[note] = gtk_image_new_from_file("assets/tiles/right.png");
    }
    else if (note == RE1 || note == RE2 || note == RE3 || note == RE4 ||
    note == SOL1 || note == SOL2 || note == SOL3 || note == SOL4 ||
    note == LA1 || note == LA2 || note == LA3 || note == LA4)
    {
      y = 2;
      highlightsNotes[note] = gtk_image_new_from_file("assets/tiles/center.png");
    }
    else
    {
      highlightsNotes[note] = gtk_image_new_from_file("assets/tiles/black.png");
    }
    gtk_container_add(GTK_CONTAINER(piano), highlightsNotes[note]); 
    gtk_fixed_move(GTK_FIXED(piano), highlightsNotes[note], x, y);
  }

}