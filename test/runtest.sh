#!/bin/bash

cd ../src
make
cd ../test
./../src/quadsolver < input.txt > actual.txt
diff actual.txt expected.txt