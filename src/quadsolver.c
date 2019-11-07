





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
	printf("**  CTRL C to quit                                                     **\n");
	printf("*************************************************************************\n");



for(;;){
	char line[1000]= {0};
	int length = 1000;
	double a, b, c = 0.0;
	printf(": ");
	int getItFlag = getIt(line, &length);
	// quit?
	if (getItFlag == GETIT_QUIT) {
		break;
	}
	int validateFlag = validate(&a, &b, &c, line, length);
	printf("a b c: %e %e %e\n", a, b, c);
	while(getItFlag != 1 || validateFlag != 1)
	{
		//Print message to the user
		if(getItFlag == -1)
		{
			printf("Unable to read user input, try again.\n: ");
		}
		else if(validateFlag == VLDT_ERR)
		{
			//TODO: figure out what to print here
			printf("Something went wrong with your input, try again.\n: ");
		}
		else if(validateFlag == VLDT_ERR_FORMAT)
		{
			printf("The input that you entered was improperly formatted, try again.\n: ");
		}
		else if(validateFlag == VLDT_ERR_A_ZERO)
		{
			printf("The input you entered had A equal to zero, which is invalid. try again: ");
		}
		else if(validateFlag == VLDT_ERR_INPUT_RANGE)
		{
			printf("The input that you entered contained something too large or small, try again.\n:");
		}
		else if (validateFlag == VLDT_ERR_RESULT_NAN)
		{
			printf("The input that you entered would have a result that is not a number, try again.\n: ");
		}
		else
		{
			printf("Something went wrong with your input, try again.\n: ");
		}
		getItFlag = getIt(line, &length);
		validateFlag = validate(&a, &b, &c, line, length);
	}
	double result1, result2 = 0.0;
	int calculateFlag = calculate(a, b, c, &result1, &result2);
	if(calculateFlag != 1)
	{
		printf("one of the input variables was an INF or NAN \n");
	}
	char output[1000]= {0};
	int formatFlag = format(result1, result2, output);
	if(formatFlag != 1)
	{
		//TODO:figure out what to do here
		printf("We don't know how this happened");
	}
	int putItFlag = putIt(output);
	if(putItFlag != 1)
	{
		printf("There was nothing to be output");
	}
}//endfor
	return 0;
}
