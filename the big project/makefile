myprog1: main.o load_program.o boolean_functions.o print_func.o
				gcc -g -ansi -Wall main.o load_program.o boolean_functions.o print_func.o  -o myprog1
main.o: main.c
			gcc -c -ansi -Wall main.c -o main.o
load_program.o: load_program.c
			gcc -c -ansi -Wall load_program.c -o load_program.o
boolean_functions.o: boolean_functions.c
		  gcc -c -ansi -Wall boolean_functions.c -o boolean_functions.o
print_func.o: print_func.c
	gcc -c -ansi -Wall print_func.c -o print_func.o
