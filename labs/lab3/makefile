LABNUM = lab3
OBJS = $(LABNUM).o AntHill.o Ant.o
SOURCES = $(LABNUM).cpp AntHill.cpp
CC = g++
LFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
CFLAGS = $(LFLAGS) -c
PRONAME = $(LABNUM)

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

$(LABNUM).o: $(LABNUM).cpp AntHill.h
	$(CC) $(CFLAGS) $(LABNUM).cpp -o $(LABNUM).o

AntHill.o: AntHill.cpp AntHill.h
	$(CC) $(CFLAGS) AntHill.cpp -o AntHill.o

Ant.o: Ant.cpp AntHill.h
	$(CC) $(CFLAGS) Ant.cpp -o Ant.o

run: all
	./$(PRONAME)

checkmem: all
	valgrind ./$(PRONAME)

clean: 
	rm $(OBJS) $(PRONAME)
