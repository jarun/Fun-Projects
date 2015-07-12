CC = gcc
CFLAGS = -W -Wall -Werror -g

all: calc

calc:
	$(CC) $(CFLAGS) -o calc calc.c
	strip calc

.PHONY: clean
clean:
	rm -f calc
