CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

all: binprint

binprint: binprint.c
	$(CC) $(CFLAGS) -o binprint binprint.c
	strip binprint

.PHONY: clean

clean:
	rm -f binprint
