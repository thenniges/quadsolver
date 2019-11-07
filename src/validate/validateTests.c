#include <stdlib.h>
#include <float.h>
#include <string.h>
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
    line = "1.0 2.0 3.0";
    //Call function
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
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
    line = "1.0 2.0 3.0";
    //Call function
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
    TEST_ASSERT_FLOAT_WITHIN(delta, 1.0, a);
    TEST_ASSERT_FLOAT_WITHIN(delta, 2.0, b);
    TEST_ASSERT_FLOAT_WITHIN(delta, 3.0, c);
}

void failure_modes_nan(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "NAN 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 NAN 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 2.0 NAN";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);
}

void failure_modes_inf(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "INF 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 INF 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 2.0 INF";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);
}

void failure_modes_input(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_FORMAT, flag);

	line = "1.0 2.0 3.0 4.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(2.0, b);
    TEST_ASSERT_EQUAL_FLOAT(3.0, c);

	line = "1.0 2.0 ywwp";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_FORMAT, flag);
}

void success_odd_input(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "1e0 2E1 3e2";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(20.0, b);
    TEST_ASSERT_EQUAL_FLOAT(300.0, c);

    line = "-1e0 -2E1 -3e2";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(-20.0, b);
    TEST_ASSERT_EQUAL_FLOAT(-300.0, c);

    line = "1e-0 2E-1 3e-2";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
    TEST_ASSERT_EQUAL_FLOAT(1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(0.2, b);
    TEST_ASSERT_EQUAL_FLOAT(0.03, c);

    line = "-1e-0 -2E-1 -3e-2";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_SUCCESS, flag);
    TEST_ASSERT_EQUAL_FLOAT(-1.0, a);
    TEST_ASSERT_EQUAL_FLOAT(-0.2, b);
    TEST_ASSERT_EQUAL_FLOAT(-0.03, c);
}

void failure_modes_large(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "4e38 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 4e38 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 2.0 4e38";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

    line = "-4e38 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 -4e38 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 2.0 -4e38";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);
}

void failure_modes_small(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "1.1e-38 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 1.1e-38 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 2.0 1.1e-38";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

    line = "-1.1e-38 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 -1.1e-38 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);

	line = "1.0 2.0 -1.1e-38";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_INPUT_RANGE, flag);
}

void failure_mode_a_zero(void) {
	//test stuff
	double a,b,c = 0;
    char* line;
    int flag;

    line = "0.0 2.0 3.0";
    flag = validate(&a, &b, &c, line, strlen(line));
    TEST_ASSERT_EQUAL_INT(VLDT_ERR_A_ZERO, flag);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(simple_float_input);
    RUN_TEST(simple_float_input_with_delta);
	RUN_TEST(failure_modes_nan);
	RUN_TEST(failure_modes_inf);
	RUN_TEST(failure_modes_input);
	RUN_TEST(success_odd_input);
	RUN_TEST(failure_modes_large);
	RUN_TEST(failure_modes_small);
	RUN_TEST(failure_mode_a_zero);
    return UNITY_END();
}
