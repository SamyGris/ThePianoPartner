# Makefile

CC = gcc 
CPPFLAGS= `pkg-config --cflags sdl` -MMD
CFLAGS = -Wall -Wextra -Werror -std=c99 -O3
LDFLAGS = 
LDLIBS= `pkg-config --libs sdl` -lSDL_mixer

EXE = main

all: ${EXE}

main	:	main.o son.o
main.o	:	main.c
son.o	:	son.c son.h

.PHONY: clean

clean:
	${RM} $(EXE) *~ *# *.o *.d

# END
