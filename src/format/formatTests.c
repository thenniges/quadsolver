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
    int flag = 0;
    char actual[80];
    char * expected = "The roots of this function are 1.001000e+00 and 2.001000e+00.\n";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.001, result1);
    TEST_ASSERT_EQUAL_FLOAT(2.001, result2);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void simple_output_message_with_a_Nan(void) {
    //test stuff
    double result1 = NAN;
    double result2 = 2.001;
    int flag = 0;
    char actual[80];
    char * expected = "The roots of this function are nan and 2.001000e+00.\n";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_IS_NAN(result1);
    TEST_ASSERT_EQUAL_FLOAT(2.001, result2);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void simple_output_message_with_2_Nans(void) {
    //test stuff
    double result1 = NAN;
    double result2 = NAN;
    int flag = 0;
    char actual[80];
    char * expected = "The roots of this function are nan and nan.\n";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_IS_NAN(result1);
    TEST_ASSERT_FLOAT_IS_NAN(result2);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void simple_output_message_with_an_inf(void) {
    //test stuff
    double result1 = 1.001;
    double result2 = INFINITY;
    int flag = 0;
    char actual[80];
    char * expected = "The roots of this function are 1.001000e+00 and inf.\n";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.001, result1);
    TEST_ASSERT_FLOAT_IS_INF(result2);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void simple_output_message_with_2_infs(void) {
    //test stuff
    double result1 = INFINITY;
    double result2 = INFINITY;
    int flag = 0;
    char actual[80];
    char * expected = "The roots of this function are inf and inf.\n";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_IS_INF(result1);
    TEST_ASSERT_FLOAT_IS_INF(result2);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void simple_output_message_with_negative_infs(void) {
    //test stuff
    double result1 = -INFINITY;
    double result2 = -INFINITY;
    int flag = 0;
    char actual[80];
    char * expected = "The roots of this function are -inf and -inf.\n";
    //Call function
    flag = format(result1, result2, actual);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_IS_NEG_INF(result1);
    TEST_ASSERT_FLOAT_IS_NEG_INF(result2);
    TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(simple_output_message);
    RUN_TEST(simple_output_message_with_a_Nan);
    RUN_TEST(simple_output_message_with_2_Nans);
    RUN_TEST(simple_output_message_with_an_inf);
    RUN_TEST(simple_output_message_with_2_infs);
    RUN_TEST(simple_output_message_with_negative_infs);
    return UNITY_END();
}