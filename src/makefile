
# Copyright 2019 Blacktop Group

# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std=c11


quadsolver: quadsolver.o getIt.o putIt.o format.o calculate.o validate.o log.o
	${CC} ${CFLAGS} getIt.o putIt.o format.o calculate.o validate.o quadsolver.o log.o -o quadsolver -lm

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

log.o : logging/log.c logging/logger.h
	${CC} ${CFLAGS} -c logging/log.c

clean:
	rm -f *.o core quadsolver

tar:
	tar -cvf ../../blacktop_qs.tar ../../quadsolver/

tarsrc:
	tar -cvf ../blacktop_qs_src.tar ../src/

