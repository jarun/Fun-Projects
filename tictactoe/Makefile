CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: tictactoe

tictactoe:
	$(CC) $(CFLAGS) -o tictactoe tictactoe.c
	strip tictactoe

.PHONY: clean
clean:
	rm -f tictactoe
