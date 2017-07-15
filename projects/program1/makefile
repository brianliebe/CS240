LABNUM = program1
OBJS = $(LABNUM).o AntHill.o Ant.o LinkedList.o
SOURCES = $(LABNUM).cpp AntHill.cpp Ant.cpp LinkedList.cpp
HEADERS = AntHill.h Ant.h LinkedList.h
CC = g++
LFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
CFLAGS = $(LFLAGS) -c
PRONAME = $(LABNUM)

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

$(LABNUM).o: $(LABNUM).cpp $(HEADERS)
	$(CC) $(CFLAGS) $(LABNUM).cpp -o $(LABNUM).o

AntHill.o: AntHill.cpp $(HEADERS)
	$(CC) $(CFLAGS) AntHill.cpp -o AntHill.o

Ant.o: Ant.cpp $(HEADERS)
	$(CC) $(CFLAGS) Ant.cpp -o Ant.o

LinkedList.o: LinkedList.cpp $(HEADERS)
	$(CC) $(CFLAGS) LinkedList.cpp -o LinkedList.o

run: all
	./$(PRONAME)

checkmem: all
	valgrind ./$(PRONAME)

clean: 
	rm -f $(OBJS) $(PRONAME)

clean-full: clean
	rm -f anthill.log

print: all
	./$(PRONAME)
	cat anthill.log
