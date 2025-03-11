all: dice

dice: Dice.o main.o
	g++ -o dice main.o Dice.o

Dice.o: Dice.cpp Dice.h
	g++ -c Dice.cpp

main.o: main.cpp Dice.h
	g++ -c main.cpp

	
