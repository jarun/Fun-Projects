CC = gcc
CFLAGS = -W -Wall -Werror -g

all: calc

calc: calc.c
	gcc $(CFLAGS) -o calc calc.c

.PHONY: clean
clean:
	-rm -f calc
