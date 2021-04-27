#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <err.h>
#include "sound.h"

int main(int argc,char *argv[])
{
  if (argc>100)
    {
      errx(3,"t con");
    }
  char *tep1="DO";
  char *tep2="RE";
  char *tep3="MI";
  char *resa[]={tep1,tep2,tep3};
  char **res=resa;
  int nbb= atoi(argv[1]);
  playNote(nbb,res);
  
  return 0;
  }

