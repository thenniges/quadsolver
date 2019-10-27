#include <stdlib.h>
#include <float.h>
#include "getIt.h"
#include "../../Unity/src/unity.h"

void setUp(void) {
    // set stuff up here
    //This will run at the beginning of every tests so you can put common code here
}

void tearDown(void) {
    // clean stuff up here
    //This will run at the end of every test so you can do common clean up here
}

void empty_input(void) {
  // nothing but eol
}

void zero_length_input(void) {
  // just /0
}

void big_input(void) {
  // inputs that will be truncated
}

void giant_input(void) {
  // stuff a novel in there, see what happens
}

void simple_float_input(void) {
  // generate some actual formatted floats and run them through
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    // call tests here
    return UNITY_END();
}
