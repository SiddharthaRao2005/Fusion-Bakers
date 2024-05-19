CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = final

SRCS = mainmenu.c checkout.c stocks.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c checkout.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c stocks.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)
