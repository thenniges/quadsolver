CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std=c11

quadsolver: quadsolver.o getIt.o putIt.o format.o calculate.o validate.o
	${CC} ${CFLAGS} getIt.o putIt.o format.o calculate.o validate.o quadsolver.o -o quadsolver

quadsolver.o: quadsolver.c
	${CC} ${CFLAGS} -c quadsolver.c

getIt.o: getIt/getIt.c getIt/getIt.h
	${CC} ${CFLAGS} -c getIt/getIt.c

putIt.o: putIt/putIt.c putIt/putIt.h
	${CC} ${CFLAGS} -c putIt/putIt.c

format.o: format/format.c format/format.h
	${CC} ${CFLAGS} -c format/format.c

calculate.o: calculate/calculate.c calculate/calculate.h
	${CC} ${CFLAGS} -c calculate/calculate.c

validate.o: validate/validate.c validate/validate.h
	${CC} ${CFLAGS} -c validate/validate.c

clean:
	rm -f *.o core quadsolver
