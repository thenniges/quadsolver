#include <stdlib.h>
#include <float.h>
#include "validate.h"
#include "../../Unity/src/unity.h"

void setUp(void) {
    // set stuff up here
    //This will run at the beginning of every tests so you can put common code here
}

void tearDown(void) {
    // clean stuff up here
    //This will run at the end of every test so you can do common clean up here
}

void simple_float_input(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;
    line = "1.0, 2.0, 3.0";
    //Call function
    flag = validate(&a, &b, &c, line, 13);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(2.0, b);
    TEST_ASSERT_EQUAL_FLOAT(3.0, c);
}

void simple_float_input_with_delta(void) {
	//more test stuff
	double a,b,c = 0;
    char* line;
    int flag;
    double delta = 100.0 * DBL_EPSILON;
    line = "1.0, 2.0, 3.0";
    //Call function
    flag = validate(&a, &b, &c, line, 13);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, 1.0, a);
    TEST_ASSERT_FLOAT_WITHIN(delta, 2.0, b);
    TEST_ASSERT_FLOAT_WITHIN(delta, 3.0, c);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(simple_float_input);
    RUN_TEST(simple_float_input_with_delta);
    return UNITY_END();
}