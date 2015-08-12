CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: calc

calc:
	$(CC) $(CFLAGS) -o calc calc.c
	strip calc

.PHONY: clean
clean:
	rm -f calc
