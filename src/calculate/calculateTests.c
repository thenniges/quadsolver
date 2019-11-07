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
    double c = 1.0;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(2.0, b);
    TEST_ASSERT_EQUAL_FLOAT(1.0, c);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, result1);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, result2);
}

void simple_int_calculate_test2(void) {
    //test stuff
    double tx1 = 1.0;
    double tx2 = 2.0;
    double a = -1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test3(void) {
    //test stuff
    double tx1 = -2.0;
    double tx2 = 1.0;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test4(void) {
    //test stuff
    double tx1 = -2.0;
    double tx2 = 1.0;
    double a = -1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}


void simple_int_calculate_test5(void) {
    //test stuff
    double tx1 = -2.0;
    double tx2 = -1.0;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test6(void) {
    //test stuff
    double tx1 = -2.0;
    double tx2 = -1.0;
    double a = -1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test7(void) {
    //test stuff
    double tx1 = -3.0;
    double tx2 = -3.0;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test8(void) {
    //test stuff
    double tx1 = -3.0;
    double tx2 = -3.0;
    double a = -13.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test9(void) {
    //test stuff
    double tx1 = 3.0;
    double tx2 = 3.0;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test10(void) {
    //test stuff
    double tx1 = 3.0;
    double tx2 = 3.0;
    double a = -17.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test11(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 5.0;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test12(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 5.0;
    double a = 19.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test13(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 5.0;
    double a = -19.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test14(void) {
    //test stuff
    double tx1 = -5.0;
    double tx2 = 0.0;
    double a = 1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test15(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 5.0;
    double a = 23.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test16(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 5.0;
    double a = -23.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test17(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 0.0;
    double a = 1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test18(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 0.0;
    double a = 7.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_int_calculate_test19(void) {
    //test stuff
    double tx1 = 0.0;
    double tx2 = 0.0;
    double a = -11.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(tx1, result1);
    TEST_ASSERT_EQUAL_FLOAT(tx2, result2);
}

void simple_double_calculate_with_delta(void) {
    //more test stuff
    double tx1 = 3.1;
    double tx2 = 3.3;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    double delta = 100.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(-tx1 + -tx2, b);
    TEST_ASSERT_EQUAL_FLOAT(tx1 * tx2, c);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta2(void) {
    //more test stuff
    double tx1 = 1.1;
    double tx2 = 2.1;
    double a = 1.0;
    double b = -tx1 + -tx2;
    double c = tx1 * tx2;
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta3(void) {
    //more test stuff
    double tx1 = 1.1;
    double tx2 = 2.1;
    double a = -1.1;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 100.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta4(void) {
    //more test stuff
    double tx1 = -2.1;
    double tx2 = 1.1;
    double a = 1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta5(void) {
    //more test stuff
    double tx1 = -2.1;
    double tx2 = 1.1;
    double a = -1.1;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta6(void) {
    //more test stuff
    double tx1 = -2.1;
    double tx2 = -1.1;
    double a = 1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta7(void) {
    //more test stuff
    double tx1 = -2.1;
    double tx2 = -1.1;
    double a = -1.1;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta8(void) {
    //more test stuff
    double tx1 = -3.1;
    double tx2 = -3.1;
    double a = 1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta9(void) {
    //more test stuff
    double tx1 = -3.1;
    double tx2 = -3.1;
    double a = -13.1;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta10(void) {
    //more test stuff
    double tx1 = 3.1;
    double tx2 = 3.1;
    double a = 1.0;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_double_calculate_with_delta11(void) {
    //more test stuff
    double tx1 = 3.1;
    double tx2 = 3.1;
    double a = -17.1;
    double b = a * (-tx1 + -tx2);
    double c = a * (tx1 * tx2);
    double result1, result2 = 0.0;
    double delta = 4.0 * DBL_EPSILON; //Relative error
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(1, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx1, result1);
    TEST_ASSERT_FLOAT_WITHIN(delta, tx2, result2);
}

void simple_int_calculate_test_with_invalid_NAN_input(void) {
    //test stuff
    double a = NAN;     //tests inputs for NAN
    double b = NAN;
    double c = NAN;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(-1, flag);
    TEST_ASSERT_EQUAL_FLOAT(NAN, a);
    TEST_ASSERT_EQUAL_FLOAT(NAN, b);
    TEST_ASSERT_EQUAL_FLOAT(NAN, c);

}

void simple_int_calculate_test_with_invalid_INF_input(void) {
    //test stuff
    double a = INFINITY;    //tests inputs for INF
    double b = INFINITY;
    double c = INFINITY;
    double result1, result2 = 0.0;
    int flag;
    //Call function
    flag = calculate(a, b, c, &result1, &result2);
    TEST_ASSERT_EQUAL_INT(-1, flag);
    TEST_ASSERT_EQUAL_FLOAT(INFINITY, a);
    TEST_ASSERT_EQUAL_FLOAT(INFINITY, b);
    TEST_ASSERT_EQUAL_FLOAT(INFINITY, c);

}

void simple_int_calculate_with_INF(void) {
    //more test stuff
    double a = 0.0;     //a is zero, causing a devide by zero
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
    double a = 2.0;     //the determinant becomes less than zero
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
    RUN_TEST(simple_int_calculate_test2);
    RUN_TEST(simple_int_calculate_test3);
    RUN_TEST(simple_int_calculate_test4);    
    RUN_TEST(simple_int_calculate_test5);
    RUN_TEST(simple_int_calculate_test6);
    RUN_TEST(simple_int_calculate_test7);
    RUN_TEST(simple_int_calculate_test8);
    RUN_TEST(simple_int_calculate_test9);
    RUN_TEST(simple_int_calculate_test10);
    RUN_TEST(simple_int_calculate_test11);
    RUN_TEST(simple_int_calculate_test12);
    RUN_TEST(simple_int_calculate_test13);
    RUN_TEST(simple_int_calculate_test14);
    RUN_TEST(simple_int_calculate_test15);
    RUN_TEST(simple_int_calculate_test16);
    RUN_TEST(simple_int_calculate_test17);
    RUN_TEST(simple_int_calculate_test18);
    RUN_TEST(simple_int_calculate_test19);
    RUN_TEST(simple_double_calculate_with_delta);
    RUN_TEST(simple_double_calculate_with_delta2);
    RUN_TEST(simple_double_calculate_with_delta3);
    RUN_TEST(simple_double_calculate_with_delta4);
    RUN_TEST(simple_double_calculate_with_delta5);
    RUN_TEST(simple_double_calculate_with_delta6);
    RUN_TEST(simple_double_calculate_with_delta7);
    RUN_TEST(simple_double_calculate_with_delta8);
    RUN_TEST(simple_double_calculate_with_delta9);
    RUN_TEST(simple_double_calculate_with_delta10);
    // RUN_TEST(simple_double_calculate_with_delta11);
    RUN_TEST(simple_int_calculate_test_with_invalid_NAN_input);
    RUN_TEST(simple_int_calculate_test_with_invalid_INF_input);
    RUN_TEST(simple_int_calculate_with_INF);
    RUN_TEST(simple_int_calculate_with_NAN);
    return UNITY_END();
}