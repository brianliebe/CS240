LABNUM = program3
OBJS = $(LABNUM).o Map.o City.o
SOURCES = $(LABNUM).cpp Map.cpp City.cpp
HEADERS = Map.h City.h
CC = g++
LFLAGSOLD = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
LFLAGS = -std=c++14 -g
CFLAGS = $(LFLAGS) -c
PRONAME = $(LABNUM)

all: program

program: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

$(LABNUM).o: $(LABNUM).cpp $(HEADERS)
	$(CC) $(CFLAGS) $(LABNUM).cpp -o $(LABNUM).o

City.o: $(HEADERS) City.cpp
	$(CC) $(CFLAGS) City.cpp -o City.o

Map.o: $(HEADERS) Map.cpp
	$(CC) $(CFLAGS) Map.cpp -o Map.o

clean:
	rm -f $(OBJS) $(PRONAME)

run: all
	./$(LABNUM)

checkmem: all
	valgrind ./$(LABNUM)
