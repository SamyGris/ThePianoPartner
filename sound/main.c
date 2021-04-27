#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <err.h>
#include "sound.h"

int main(int argc,char *argv[])
{
  if (argc != 0)
    errx(3,"Veuillez ecrire les notes a jouer");
  
  char **res=argv;
  playNote(res,argc);
  
  return 0;
  }

