CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std =c11

quadsolver: quadsolver.o
	${CC} ${CFLAGS} quadsolver.o -o quadsolver

quadsolver.o: quadsolver.c quadsolver.h
	${CC} ${CFLAGS} -c quadsolver.c

test:
	

clean:
	rm -f *.o core quadsolver
