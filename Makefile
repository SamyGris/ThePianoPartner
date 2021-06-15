SRC		= src/main.c \
		  src/piano.c \
		  src/sound.c \
		  src/constantes.c \
		  src/toolbox.c 

OBJ        = $(SRC:.c=.o)
 
DIRH       = -Iheaders/

CC         = gcc
CPPFLAGS = `pkg-config --cflags gtk+-3.0` -MMD
CFLAGS = -Wall -Wextra -Werror -std=c99 -O3 -I /usr/local/include/ 
LDFLAGS = -pthread -export-dynamic -rdynamic
LDLIBS = `pkg-config --libs gtk+-3.0` -L /usr/local/lib/ -lfmod -lm -fuse-ld=gold 

NAME	= tpp

all:        $(NAME)

$(NAME)        : $(OBJ)
	$(CC) -o $(NAME) $(DIRH) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDLIBS) $(LDFLAGS)

clean:
	rm -f $(OBJ) src/*.d $(NAME)