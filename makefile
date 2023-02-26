all: main
	rm main.o
	rm IntVector.o
main: IntVector.o main.o
	gcc -o myfile IntVector.o main.o

main.o: main.c
	gcc -c main.c

IntVector.o: IntVector.c
	gcc -c IntVector.c