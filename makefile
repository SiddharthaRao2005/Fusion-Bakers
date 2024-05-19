CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = main_menu.c
OBJ = $(SRC:.c=.o)
HEADERS = inventory.h checkout_file.h

.PHONY: all clean

all: my_program

my_program: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) my_program
