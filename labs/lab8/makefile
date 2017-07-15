LABNUM = lab8
OBJS = $(LABNUM).o Hash.o
SOURCES = $(LABNUM).cpp Hash.cpp
HEADERS = Hash.h
CC = g++
LFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
CFLAGS = $(LFLAGS) -c
PRONAME = $(LABNUM)

all: program

program: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

$(LABNUM).o: $(LABNUM).cpp $(HEADERS)
	$(CC) $(CFLAGS) $(LABNUM).cpp -o $(LABNUM).o

Hash.o: $(HEADERS) Hash.cpp
	$(CC) $(CFLAGS) Hash.cpp -o Hash.o

clean:
	rm -f $(OBJS) $(PRONAME)

run: all
	./$(LABNUM)

checkmem: all
	valgrind ./$(LABNUM)
