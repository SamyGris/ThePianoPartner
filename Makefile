# Makefile

CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0` -O3 -rdynamic
LDLIBS = `pkg-config --libs gtk+-3.0`

EXE = main

all: $(EXE)

$(foreach f, $(EXE), $(eval $(f):))

.PHONY: clean

clean:
	${RM} $(EXE) *~ *#

# END
