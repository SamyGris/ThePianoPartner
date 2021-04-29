# Makefile

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -O3 -rdynamic
LDLIBS = `pkg-config --libs gtk+-3.0`

EXE = main

all: ${EXE}

main	:	main.o sound/sound.o piano.o
main.o	:	main.c
sound/sound.o	:	sound/sound.c sound/sound.h
piano.o : 	piano.c piano.h

.PHONY: clean

clean:
	${RM} $(EXE) *~ *# *.o *.d

# END
