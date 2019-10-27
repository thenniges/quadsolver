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

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    // call tests here
    return UNITY_END();
}
