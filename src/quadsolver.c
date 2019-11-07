#include <stdio.h>
#include <math.h>
#include "./getIt/getIt.h"
#include "./putIt/putIt.h"
#include "./validate/validate.h"
#include "./calculate/calculate.h"
#include "./format/format.h"

int main(int argc, char* argv[])
{

	printf("*************************************************************************\n");
	printf("**  quadsolver                                                         **\n");
	printf("**  Created By Blacktop Group:                                         **\n");
	printf("**  Allin Kahrl                                                        **\n");
	printf("**  Tyler Henniges                                                     **\n");
	printf("**  Erron Johnson                                                      **\n");
	printf("**  Skyler Sheler                                                      **\n");
	printf("*************************************************************************\n");
	printf("**                          Valid Inputs                               **\n");
	printf("**  A B and C should be entered on a single line seperated by spaces   **\n");
	printf("**  and be rounded to four significant figures. Inputs will be         **\n");
	printf("**  truncated to four significant digits.                              **\n");
	printf("**                                                                     **\n");
	printf("**  EX>  -1.000 2.123E26 3.456e-26                                     **\n");
	printf("**                                                                     **\n");
	printf("**  CTRL Z to quit                                                     **\n");
	printf("*************************************************************************\n");



// for(;;){
	char line[1000]= {0};
	int length = 1000;
	double a, b, c = 0.0;
	int getItFlag = getIt(line, &length);
	int validateFlag = validate(&a, &b, &c, line, length);
	while(getItFlag != 1 || validateFlag != 1)
	{
		//Print message to the user and log
		getItFlag = getIt(line, &length);
		validateFlag = validate(&a, &b, &c, line, length);
	}
	double result1, result2 = 0.0;
	int calculateFlag = calculate(a, b, c, &result1, &result2);
	if(calculateFlag != 1)
	{
		//DO logging
	}
	char output[1000]= {0}; 
	int formatFlag = format(result1, result2, output);
	if(formatFlag != 1)
	{
		//Do Logging
	}
	int putItFlag = putIt(output);
	if(putItFlag != 1)
	{
		//Do logging
	}
// }
	return 0;
}
