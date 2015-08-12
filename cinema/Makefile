CC = g++

CFLAGS = -Wall -Wextra -Werror -g

all: tickets

tickets:
	$(CC) $(CFLAGS) -o tickets tickets.cpp
	strip tickets

.PHONY: clean
clean:
	rm -f tickets
