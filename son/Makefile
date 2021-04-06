# Makefile

CC = gcc 
CPPFLAGS =
CFLAGS = -Wall -Wextra
LDFLAGS = -I./inc -L./lib
LDLIBS = -lfmod -lfmodL

EXE = main

all: ${EXE}

main:main.o
main.o:main.c son.h

.PHONY: clean

clean:
	${RM} $(EXE) *~ *# *.o

# END
