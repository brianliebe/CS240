LABNUM = lab7
OBJS = $(LABNUM).o BSTree.o
SOURCES = $(LABNUM).cpp BSTree.cpp
CC = g++
LFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
CFLAGS = $(LFLAGS) -c
PRONAME = $(LABNUM)

all: program

program: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

$(LABNUM).o: $(LABNUM).cpp BSTree.h
	$(CC) $(CFLAGS) $(LABNUM).cpp -o $(LABNUM).o

BSTree.o: BSTree.cpp BSTree.h
	$(CC) $(CFLAGS) BSTree.cpp -o BSTree.o

clean:
	rm -f $(OBJS) $(PRONAME)

run: all
	./$(LABNUM)

checkmem: all
	valgrind ./$(LABNUM)
