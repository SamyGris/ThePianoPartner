# Makefile

CC = gcc
CPPFLAGS = `pkg-config --cflags gtk+-3.0 sdl` -rdynamic -MMD
CFLAGS = -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS = -pthread
LDLIBS = `pkg-config --libs gtk+-3.0 sdl` -lSDL_mixer -lm

EXE = main

all: ${EXE}

main	:	main.o sound.o piano.o
main.o	:	main.c widgets.h
sound.o	:	sound.c sound.h
piano.o : 	piano.c piano.h widgets.h

.PHONY: clean

clean:
	${RM} $(EXE) *~ *# *.o *.d

# END
