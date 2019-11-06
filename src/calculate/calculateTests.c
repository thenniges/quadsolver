#include <stdlib.h>
#include <float.h>
#include "calculate.h"
#include "../../Unity/src/unity.h"

void setUp(void) {
    // set stuff up here
    //This will run at the beginning of every tests so you can put common code here
}

void tearDown(void) {
    // clean stuff up here
    //This will run at the end of every test so you can do common clean up here
}

void simple_int_calculate_test(void) {
	//test stuff
	double a = 1.0;
    double b = 2.0;
    double c = -3.0;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(2.0, b);
    TEST_ASSERT_EQUAL_FLOAT(-3.0, c);
    TEST_ASSERT_EQUAL_FLOAT(1.0, result1);
    TEST_ASSERT_EQUAL_FLOAT(-3.0, result2);
}

void simple_int_calculate_with_delta(void) {
    //more test stuff
    double a = 1.0;
    double b = 2.0;
    double c = -3.0;
    double result1, result2 = 0.0;
    double delta = 100.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(2.0, b);
    TEST_ASSERT_EQUAL_FLOAT(-3.0, c);
    TEST_ASSERT_FLOAT_WITHIN(delta, 1.0, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, -3.0, result2);
}

void simple_int_calculate_with_INF(void) {
    //more test stuff
    double a = 0.0;
    double b = 2.0;
    double c = -3.0;
    double result1, result2 = 0.0;
    double delta = 100.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(0.0, a);
    TEST_ASSERT_EQUAL_FLOAT(2.0, b);
    TEST_ASSERT_EQUAL_FLOAT(-3.0, c);
    TEST_ASSERT_FLOAT_WITHIN(delta, -NAN, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, -INFINITY, result2);
}

void simple_int_calculate_with_NAN(void) {
    //more test stuff
    double a = 2.0;
    double b = 0.0;
    double c = 3.0;
    double result1, result2 = 0.0;
    double delta = 100.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(2.0, a);
    TEST_ASSERT_EQUAL_FLOAT(0.0, b);
    TEST_ASSERT_EQUAL_FLOAT(3.0, c);
    TEST_ASSERT_FLOAT_WITHIN(delta, NAN, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, NAN, result2);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(simple_int_calculate_test);
    RUN_TEST(simple_int_calculate_with_delta);
    RUN_TEST(simple_int_calculate_with_INF);
    RUN_TEST(simple_int_calculate_with_NAN);
    return UNITY_END();
}