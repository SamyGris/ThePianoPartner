#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h" 
#include "SDL/SDL_mixer.h"
#include <pthread.h>
#include "err.h"
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "sound.h"

void playNote(float frequency,char file)
{
   //Initialisation de l'API Mixer
   if(Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048) == -1)
   {
      printf("%s", Mix_GetError());
   }
   
  Mix_Music *note; //Structure Mix_Music correspondante à la note

  switch (file)
  {
  case 1:
    note = Mix_LoadMUS("notes/DO1.wav");

    break;
  case 2 : 
    note = Mix_LoadMUS("notes/DO2.wav");

    break;
  case 3:
    note = Mix_LoadMUS("notes/DO3.wav");

    break;
  
  default:
    note = Mix_LoadMUS("notes/DO4.wav");
    break;
  }
  
  Mix_PlayMusic(note, 1);//Jouer la note
   
   SDL_Delay(3000);
   Mix_FreeMusic(note);
   Mix_CloseAudio();
   
}


void* worker(void *arg)
{

  float coeff = 1.05946 ;  
  char* input = (char *)arg ; 

  if (strlen(input) < 3)
  {
    errx(1,"Please Check your arguments ! Keep in mind that you have to call the funtion with the note and the number of the octave example : DO2 \n") ; 
  }
  char n = input[2] ; 
  char nb = atol(&n) ; 
  

  
  
   static int frequency ; 
  if (input[0] == 'D' && input[1] == 'O') 
  {

        frequency = 44000 ;
        
      playNote(frequency,nb);
    
  } 

  else  if (input[0] == 'D' && input[1] == 'Z') 
  {
    frequency = (44000 * pow(coeff,1)) ;
    
    printf("Frequency = %d \n ",frequency) ; 
    playNote(frequency,nb);
  } 

else  if (input[0] == 'R' && input[1] == 'E') 
  {
    frequency = (44000 * pow(coeff,2)) ;
    printf("Frequence de RÉ : %d \n", frequency) ; 
   //frequency *= pow(2,nb) ;
    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'R' && input[1] == 'Z') 
  {
   
   frequency = (44000 * pow(coeff,3)) ;

    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'M' && input[1] == 'I') 
  {
    frequency = (44000 * pow(coeff,4)) ;

    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'F' && input[1] == 'A') 
  {
    frequency = (44000 * pow(coeff,5)) ;

    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'F' && input[1] == 'Z') 
  {
    frequency = (44000 * pow(coeff,6)) ;
    
    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'S' && input[1] == 'O') 
  {
   frequency = (44000 * pow(coeff,7)) ;
   
    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'S' && input[1] == 'Z') 
  {
   frequency = (44000 * pow(coeff,8)) ;
  
    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 


  else  if (input[0] == 'L' && input[1] == 'A') 
  {
    frequency = (44000 * pow(coeff,9)) ;
   
    playNote(frequency,nb);
  } 


  else  if (input[0] == 'L' && input[1] == 'Z') 
  {
    frequency = (44000 * pow(coeff,10)) ;
    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  else  if (input[0] == 'S' && input[1] == 'I') 
  {
    printf("%f" , pow(coeff,11) ) ; 
    frequency = (44000 * pow(coeff,11)) ;
    printf("Frequency = %d",frequency) ; 
    playNote(frequency,nb);
  } 

  
    return EXIT_SUCCESS;
}


void play_this(char* note) 
{

if (strlen(note) < 2)
    errx(1,"Please check your arguments");

  char second[15] = "";
  strcat(second,note) ;

    pthread_t handler;

    
   
    pthread_create(&handler,NULL,worker,&second);
    
    pthread_join(handler,NULL) ;
  


}
