# Makefile

CC = gcc
CPPFLAGS = `pkg-config --cflags gtk+-3.0` -MMD
CFLAGS = -Wall -Wextra -Werror -std=c99 -O3 -I /usr/local/include/ 
LDFLAGS = -pthread -export-dynamic -rdynamic
LDLIBS = `pkg-config --libs gtk+-3.0` -L /usr/local/lib/ -lfmod -lm -fuse-ld=gold

EXE = main

all: ${EXE}

main	:	main.o sound.o piano.o toolbox.o
main.o	:	main.c widgets.h
sound.o	:	sound.c sound.h
piano.o : 	piano.c piano.h widgets.h toolbox.h
toolbox.o:	toolbox.c toolbox.h

.PHONY: clean

clean:
	${RM} $(EXE) *~ *# *.o *.d

# END
