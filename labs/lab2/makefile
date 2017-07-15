OBJS = lab2.o AntHill.o
SOURCES = lab2.cpp AntHill.cpp
CC = g++
LFLAGS = -Wall -Wextra -DDEBUG -g -pedantic -std=c++14
CFLAGS = $(LFLAGS) -c
PRONAME = lab2

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(PRONAME)

lab2.o: lab2.cpp AntHill.h
	$(CC) $(CFLAGS) lab2.cpp -o lab2.o

AntHill.o: AntHill.cpp AntHill.h
	$(CC) $(CFLAGS) AntHill.cpp -o AntHill.o

run: all
	./$(PRONAME)

checkmem: all
	valgrind ./$(PRONAME)

clean: 
	rm $(OBJS) $(PRONAME)
