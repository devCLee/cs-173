all: complex

complex: main.o Complex.o
	g++ -o complex main.o Complex.o

main.o: main.cpp Complex.h
	g++ -c main.cpp

Complex.o: Complex.cpp Complex.h
	g++ -c Complex.cpp
