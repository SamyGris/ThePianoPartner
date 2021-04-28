#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

// Définition des notes

enum {DO1, RE1, MI1, FA1, SOL1, LA1, SI1,
      DOD1, RED1, FAD1, SOLD1, LAD1,
      DO2, RE2, MI2, FA2, SOL2, LA2, SI2,
      DOD2, RED2, FAD2, SOLD2, LAD2,
      DO3, RE3, MI3, FA3, SOL3, LA3, SI3,
      DOD3, RED3, FAD3, SOLD3, LAD3,
      DO4, RE4, MI4, FA4, SOL4, LA4, SI4,
      DOD4, RED4, FAD4, SOLD4, LAD4};

// Définition des gammes

enum {DOMA, REMA, MIMA, FAMA, SOLMA, LAMA, SIMA,
      DODMA, REDMA, FADMA, SOLDMA, LADMA,
      DOMI, REMI, MIMI, FAMI, SOLMI, LAMI, SIMI,
      DODMI, REDMI, FADMI, SOLDMI, LADMI};

// Définition des notes en fonction des gammes majeures et mineures

int scaleNotes[24][7];

// Définition des accords

int chords[24][3];

// Coordonnees

int coordonesX[48];

#endif
