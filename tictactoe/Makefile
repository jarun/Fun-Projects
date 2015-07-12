CC = gcc
CFLAGS = -W -Wall -Werror -g

all: tictactoe

tictactoe:
	$(CC) $(CFLAGS) -o tictactoe tictactoe.c
	strip tictactoe

.PHONY: clean
clean:
	rm -f tictactoe
