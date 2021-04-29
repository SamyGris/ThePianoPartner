#include "sound.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h" 
#include "SDL/SDL_mixer.h"
#include <pthread.h>
#include "err.h"
#include <unistd.h>
#include <string.h>
#include <math.h> 


int main(int argc , char* argv[]) 
{


  if (argc < 2)
    errx(1,"Please check your arguments");


  play_this(argv[1]) ; 
  


  return 0;
}
