CC=g++
CFLAGS=-I.

all:test

test: test.o CPoint.o 
	g++ CPoint.o test.o -o test.out

CPoint.o: CPoint.cpp CPoint.h
	g++ -c CPoint.cpp

test.o: test.cpp LinkedList.h LinkedList.hpp 
	g++ -c test.cpp
clean:
	rm *.o 
showall:
	gvim -p CPoint.h CPoint.cpp LinkedList.h LinkedList.hpp test.cpp


	

