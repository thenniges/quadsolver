#include <stdlib.h>
#include <float.h>
#include "format.h"
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
	//test stuff
	double result1 = 1.001;
    double result2 = 2.001;
    double delta = 100.0 * DBL_EPSILON;
    int flag = 0;
    char* actual = NULL;
    char* expected = "The roots of this function are 1.001 and 2.001";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, 1.001, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, 2.001, result2);
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, 46);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(simple_output_message);
    return UNITY_END();
}