all: program

program: lab6.o Sorter.h
	g++ lab6.o -o lab6

lab6.o: lab6.cpp Sorter.h
	g++ -c lab6.cpp -o lab6.o

clean:
	rm *.o lab6 -f

run: all
	./lab6

checkmem: all
	valgrind ./lab6
