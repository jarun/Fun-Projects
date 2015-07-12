CC = g++

CFLAGS = -W -Wall -Werror -g

all: tickets

tickets:
	$(CC) $(CFLAGS) -o tickets tickets.cpp
	strip tickets

.PHONY: clean
clean:
	rm -f tickets
