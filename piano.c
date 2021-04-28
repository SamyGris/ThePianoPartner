#include "constantes.h"
#include "sound/sound.h"
#include <stdlib.h>

void init()
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
}

void playChords(int usrChords[], int repet[], int* stopped, int bpm)
{
  int inter = 60000/bpm * 4;
  while (!*stopped)
  {
    for (int i = 0; i < 8; i++)
    {
      if (usrChords[i] != NULL)
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

void playChord(int chord, int inter)
{
  playNote(chords[chord][0]);
  displayNote(chords[chord][0], inter);
  playNote(chords[chord][0]);
  displayNote(chords[chord][0], inter);
  playNote(chords[chord][0]);
  displayNote(chords[chord][0], inter);
}

int main()
{
  int* stopped = malloc(sizeof(int));
  *stopped = 0;
  int myChords[8] = {LAMI, SOLMA, FAMA, MIMA, NULL, NULL, NULL, NULL};
  int repet[8] = {2, 2, 2, 2, 0, 0, 0, 0};
  
  playChords(myChords, repet, stopped, 100);

  return 0;
}