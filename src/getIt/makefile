
# Copyright 2019 Blacktop Group

# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



CC = gcc
CFLAGS = -ggdb -Wall -pedantic -std=c11

get: get.o getIt.o
	${CC} ${CFLAGS} get.o getIt.o -o get

getItTests: getIt.o getItTests.o ../../Unity/src/unity.c
	${CC} ${CFLAGS} ../../Unity/src/unity.c getIt.o getItTests.o -o getItTests

get.o: get.c
	${CC} ${CFLAGS} -c get.c

getIt.o: getIt.c getIt.h
	${CC} ${CFLAGS} -c getIt.c

getItTests.o: getItTests.c ../../Unity/src/unity.h getIt.h
	${CC} ${CFLAGS} -c getItTests.c

clean:
	rm -rf *.o getItTests core
