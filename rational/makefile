all: main

main: main.o Rational.o
	g++ -o main main.o Rational.o
	
main.o: main.cpp Rational.h
	g++ -c -g main.cpp
	
Rational.o: Rational.cpp Rational.h
	g++ -c -g Rational.cpp