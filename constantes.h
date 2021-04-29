#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

// Structure définissant une note
struct noteData
{
      int note;
      int inter;
}

// Définition des notes

enum {DO1, DOD1, RE1, RED1, MI1, FA1, FAD1, SOL1, SOLD1, LA1, LAD1, SI1,
      DO2, DOD2, RE2, RED2, MI2, FA2, FAD2, SOL2, SOLD2, LA2, LAD2, SI2,
      DO3, DOD3, RE3, RED3, MI3, FA3, FAD3, SOL3, SOLD3, LA3, LAD3, SI3,
      DO4, DOD4, RE4, RED4, MI4, FA4, FAD4, SOL4, SOLD4, LA4, LAD4, SI4};

// Définition des gammes

enum {DOMA, DODMA, REMA, REDMA, MIMA, FAMA, FADMA, SOLMA, SOLDMA, LAMA, LADMA, SIMA,
      DOMI, DODMI, REMI, REDMI, MIMI, FAMI, FADMI, SOLMI, SOLDMI, LAMI, LADMI, SIMI};

// Définition des notes en fonction des gammes majeures et mineures

int scaleNotes[24][7];

// Définition des accords

int chords[24][3];

// Positions des touches

int position[48];

#endif
