.PHONY: all
all: main libmymat.a
main: main.o libmymat.a
	gcc -Wall -o connections main.o libmymat.a
main.o: main.c my_mat.h
	gcc -c main.c

libmymat.a: my_mat.o
	ar  rcs libmymat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	gcc -c my_mat.c -o my_mat.o
#PHONY clean:
clean:
	rm -f *.o libmymat.a connections
