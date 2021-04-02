#ifndef DEF_NOTES
#define DEF_NOTES

enum {DOMA, REMA, MIMA, FAMA, SOLMA LAMA, SIMA,
      DODMA, REDMA, FADMA, SOLDMA, LADMA,
      DOMI, REMI, MIMI, FAMI, SOLMA LAMI, SIMI,
      DODMI, REDMI, FADMI, SOLDMI, LADMI};

enum {DO1, RE1, MI1, FA1, SOL1, LA1, SI1,
      DOD1, RED1, FAD1, SOLD1, LAD1,
      DO2, RE2, MI2, FA2, SOL2, LA2, SI2,
      DOD2, RED2, FAD2, SOLD2, LAD2,
      DO3, RE3, MI3, FA3, SOL3, LA3, SI3,
      DOD3, RED3, FAD3, SOLD3, LAD3,
      DO4, RE4, MI4, FA4, SOL4, LA4, SI4,
      DOD4, RED4, FAD4, SOLD4, LAD4};

int gammes[24][7];
gammes[DOMA][0] = DO1;
gammes[DOMA][1] = RE1;
gammes[DOMA][2] = MI1;
gammes[DOMA][3] = FA1;
gammes[DOMA][4] = SOL1;
gammes[DOMA][5] = LA1;
gammes[DOMA][6] = SI1;

gammes[REMA][0] = RE1;
gammes[REMA][1] = MI1;
gammes[REMA][2] = FAD1;
gammes[REMA][3] = SOL1;
gammes[REMA][4] = LA1;
gammes[REMA][5] = SI1;
gammes[REMA][6] = DOD1;

gammes[MIMA][0] = MI1;
gammes[MIMA][1] = FAD1;
gammes[MIMA][2] = SOLD1;
gammes[MIMA][3] = LA1;
gammes[MIMA][4] = SI1;
gammes[MIMA][5] = DOD2;
gammes[MIMA][6] = RED2;

gammes[FAMA][0] = RE2;
gammes[FAMA][1] = MI2;
gammes[FAMA][2] = FAD2;
gammes[FAMA][3] = SOL2;
gammes[FAMA][4] = LA2;
gammes[FAMA][5] = SI2;
gammes[FAMA][6] = DOD2;

gammes[SOLMA][0] = SOL1;
gammes[SOLMA][1] = LA1;
gammes[SOLMA][2] = SI1;
gammes[SOLMA][3] = DO2;
gammes[SOLMA][4] = RE2;
gammes[SOLMA][5] = MI2;
gammes[SOLMA][6] = FAD2;

gammes[LAMA][0] = LA1;
gammes[LAMA][1] = SI1;
gammes[LAMA][2] = DOD2;
gammes[LAMA][3] = RE2;
gammes[LAMA][4] = MI2;
gammes[LAMA][5] = FAD2;
gammes[LAMA][6] = SOLD2;

gammes[SIMA][0] = SI1;
gammes[SIMA][1] = DOD2;
gammes[SIMA][2] = RED2;
gammes[SIMA][3] = MI2;
gammes[SIMA][4] = FAD2;
gammes[SIMA][5] = SOLD2;
gammes[SIMA][6] = LAD2;

gammes[DODMA][0] = DOD1;
gammes[DODMA][1] = RED1;
gammes[DODMA][2] = FA1;
gammes[DODMA][3] = FAD1;
gammes[DODMA][4] = SOLD1;
gammes[DODMA][5] = LAD1;
gammes[DODMA][6] = DO2;

gammes[REDMA][0] = RED1;
gammes[REDMA][1] = FA1;
gammes[REDMA][2] = SOL1;
gammes[REDMA][3] = SOLD1;
gammes[REDMA][4] = LA2;
gammes[REDMA][5] = SI2;
gammes[REDMA][6] = DOD2;

gammes[FADMA][0] = RE2;
gammes[FADMA][1] = MI2;
gammes[FADMA][2] = FAD2;
gammes[FADMA][3] = SOL2;
gammes[FADMA][4] = LA2;
gammes[FADMA][5] = SI2;
gammes[FADMA][6] = DOD2;

gammes[SOLDMA][0] = RE2;
gammes[SOLDMA][1] = MI2;
gammes[SOLDMA][2] = FAD2;
gammes[SOLDMA][3] = SOL2;
gammes[SOLDMA][4] = LA2;
gammes[SOLDMA][5] = SI2;
gammes[SOLDMA][6] = DOD2;

gammes[LADMA][0] = RE2;
gammes[LADMA][1] = MI2;
gammes[LADMA][2] = FAD2;
gammes[LADMA][3] = SOL2;
gammes[LADMA][4] = LA2;
gammes[LADMA][5] = SI2;
gammes[LADMA][6] = DOD2;


#endif
