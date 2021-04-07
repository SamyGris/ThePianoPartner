#include <stdlib.h>
#include <stdio.h>
#include "sound.h"

int main(int argc,char *argv[])
{
  if (argc != 2)
    return 1;
  
  playNote(argv[1]);
  
  return 0;
}


