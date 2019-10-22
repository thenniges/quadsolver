#!/bin/bash

# spacing from last test run
echo -e "\n\n"

cd src/validate
make
cd ../..
cd src/calculate 
make
cd ../..
cd src/format 
make
cd ../..

# and then run the tests
# the line immediately below will run the test and save the output in
# xUnit format to an xml file
#${testexecutable1} --gtest_output="xml:${testresults}"
echo -e "\nValidate\n"
./src/validate/validateTests
echo -e "\nCalculate\n"
./src/calculate/calculateTests
echo -e "\nFormat\n"
./src/format/formatTests

# newlines for good measure
echo -e "\n\n"