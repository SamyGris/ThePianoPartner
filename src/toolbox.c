#include "../headers/toolbox.h"
#include <stdio.h>
#include "../headers/constantes.h"
#include <err.h>

// Fonction sleep (en ms)
int msleep(int tms)
{
    struct timespec ts;
    int ret;

    if (tms < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = tms / 1000;
    ts.tv_nsec = (tms % 1000) * 1000000;

    do {
        ret = nanosleep(&ts, &ts);
    } while (ret && errno == EINTR);

    return ret;
}

void initFileText()
{
  fp = fopen("out.txt", "w+");
  if (fp == NULL)
  {
    errx(1, "Cannot open file"); 
  }
  fprintf(fp, "Les accords et les notes jouées: \n" );
}

char* getLengthNote(int l)
{
    switch (l)
    {
    case 0:
        return "ronde"; 
        break;
    case 1:
        return "blanche"; 
        break; 
    case 2:
        return "noire"; 
        break; 
    case 3: 
        return "croche"; 
        break; 
    case 4:
        return "double croche"; 
        break;     
    default:
        return "don't know"; 
        break;
    }
}