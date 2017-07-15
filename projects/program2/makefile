LABNUM = program2
OBJS = $(LABNUM).o Card.o Deck.o Heap.o Player.o Table.o
SOURCES = $(LABNUM).cpp Card.cpp Deck.cpp Heap.cpp Player.cpp Table.cpp
HEADERS = Player.h Card.h Deck.h Heap.h Table.h
CC = g++
OLDLFLAGS = -Wall -Wextra -DDEBUG -pedantic
LFLAGS = -g -std=c++14
CFLAGS = $(LFLAGS) -c
PRONAME = $(LABNUM)

all: program

program: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

$(LABNUM).o: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LABNUM).cpp -o $(LABNUM).o

Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) Card.cpp -o Card.o

Deck.o: Card.h Deck.h Deck.cpp
	$(CC) $(CFLAGS) Deck.cpp -o Deck.o

Heap.o: Heap.cpp Heap.h Player.h
	$(CC) $(CFLAGS) Heap.cpp -o Heap.o

Player.o: Player.cpp Player.h Card.h 
	$(CC) $(CFLAGS) Player.cpp -o Player.o

Table.o: Table.h Table.cpp Player.h 
	$(CC) $(CFLAGS) Table.cpp -o Table.o

clean:
	rm -f $(OBJS) $(PRONAME)

run: all
	./$(LABNUM)

checkmem: all
	valgrind ./$(LABNUM)
