all: main

main: main.o Date.o
	g++ -o main main.o Date.o
	
main.o: main.cpp Date.h
	g++ -c main.cpp
	
Date.o: Date.cpp Date.h
	g++ -c Date.cpp