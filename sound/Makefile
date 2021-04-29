# Makefile

CC = gcc 
CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS = -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS = 
LDLIBS= `pkg-config --libs sdl` -lSDL_mixer

EXE = main

all: ${EXE}

main	:	main.o sound.o
main.o	:	main.c
sound.o	:	sound.c sound.h

.PHONY: clean

clean:
	${RM} $(EXE) *~ *# *.o *.d

# END
