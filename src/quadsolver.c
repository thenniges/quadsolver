#include <stdio.h>
#include <math.h>
#include "./getIt/getIt.h"
#include "./putIt/putIt.h"
#include "./validate/validate.h"
#include "./calculate/calculate.h"
#include "./format/format.h"

int main()
{
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

	return 0;
}
