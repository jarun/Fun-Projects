CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: thread

thread:
	$(CC) $(CFLAGS) -o thread thread.c -lpthread `xml2-config --cflags --libs`
	strip thread

.PHONY: clean
clean:
	rm -f thread
