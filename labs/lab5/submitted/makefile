SOURCES = Card.cpp Deck.cpp lab5.cpp
OBJECTS = Card.o Deck.o lab5.o
HEADERS = Card.h Deck.h Queue.h LinkedList.h
PROGRAM = lab5
CC = g++
LFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
CFLAGS = $(LFLAGS) -c

all: program

program: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(PROGRAM)

Card.o: Card.cpp $(HEADERS)
	$(CC) $(CFLAGS) Card.cpp -o Card.o

Deck.o: Deck.cpp $(HEADERS)
	$(CC) $(CFLAGS) Deck.cpp -o Deck.o

lab5.o: lab5.cpp $(HEADERS)
	$(CC) $(CFLAGS) lab5.cpp -o lab5.o

clean:
	rm *.o $(PROGRAM) -f

run: all
	./$(PROGRAM)

checkmem: all
	valgrind ./$(PROGRAM)
