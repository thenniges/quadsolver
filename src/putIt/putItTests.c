#include <stdlib.h>
#include <float.h>
#include "putIt.h"
#include "../../Unity/src/unity.h"

void setUp(void) {
    // set stuff up here
    //This will run at the beginning of every tests so you can put common code here
}

void tearDown(void) {
    // clean stuff up here
    //This will run at the end of every test so you can do common clean up here
}

void simple_output_message(void) {
    int flag = 0;
    char * actual = "The roots of this function are 1.001 and 2.001.";
    char * expected = "The roots of this function are 1.001 and 2.001.";
    //Call function
    flag = putIt(actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    // call tests here
    RUN_TEST(simple_output_message);
    return UNITY_END();
}
