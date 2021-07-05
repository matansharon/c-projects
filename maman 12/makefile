myprog1: main.o functions.o
	gcc -g  main.o functions.o -o myprog1

main.o: main.c data.h
	gcc -c -ansi -Wall main.c -o main.o

functions.o:  functions.c data.h
	gcc -c -ansi -Wall  functions.c -o  functions.o
