





#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "./getIt/getIt.h"
#include "./putIt/putIt.h"
#include "./validate/validate.h"
#include "./calculate/calculate.h"
#include "./format/format.h"
#include "./logging/logger.h"
#define TAG "__TEST_STATUS__"
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
	printf("**  CTRL C or type quit to quit                                        **\n");
	printf("*************************************************************************\n");

	int log = 0;
	if(argv[1]!=NULL){
		if(strcmp(argv[1],"logging")==0){
			log=1;
			printf("\n\n%s\n\n", "########################### LOGGING ENABLED #############################");
		}
	}

for(;;){
	char line[1000]= {0};
	int length = 1000;
	double a, b, c = 0.0;
	printf(": ");
	int getItFlag = getIt(line, &length);
	if(log==1){
		
		if(getItFlag==1){
			logger(TAG, "GETIT PASSED\t");
			// logger(TAG, "DO IT AGAIN\t");
		}
		else{
			logger(TAG, "GETIT FAILED\t");
		}
	}
	// quit?
	if (getItFlag == GETIT_QUIT) {
		break;
	}
	int validateFlag = validate(&a, &b, &c, line, length);
	
	// printf("a b c: %e %e %e\n", a, b, c);
	while(getItFlag != 1 || validateFlag != 1)
	{
		//Print message to the user
		if(getItFlag == -1)
		{
			if(log==1){
				logger(TAG, "VALIDATE CANT READ INPUT\t");
			}
			printf("Unable to read user input, try again.\n: ");
		}
		else if(validateFlag == VLDT_QUIT)
		{
			if(log==1){
				logger(TAG, "VALIDATE QUIT\t");
			}
			return 0;
		}
		else if(validateFlag == VLDT_ERR)
		{
			if(log==1){
				logger(TAG, "VALIDATE BAD INPUT\t");
			}
			//TODO: figure out what to print here
			printf("Something went wrong with your input, try again.\n: ");
		}
		else if(validateFlag == VLDT_ERR_FORMAT)
		{
			if(log==1){
				logger(TAG, "VALIDATE BAD FORMAT\t");
			}
			printf("The input that you entered was improperly formatted, try again.\n: ");
		}
		else if(validateFlag == VLDT_ERR_A_ZERO)
		{
			if(log==1){
				logger(TAG, "VALIDATE EQUAL ZERO\t");
			}
			printf("The input you entered had A equal to zero, which is invalid. try again: ");
		}
		else if(validateFlag == VLDT_ERR_INPUT_RANGE)
		{
			if(log==1){
				logger(TAG, "VALIDATE BAD INPUT RANGE\t");
			}
			printf("The input that you entered contained something too large or small, try again.\n: ");
		}
		else if (validateFlag == VLDT_ERR_RESULT_NAN)
		{
			if(log==1){
				logger(TAG, "VALIDATE NAN\t");
			}
			printf("The input that you entered would have a result that is not a number, try again.\n: ");
		}
		else
		{
			if(log==1){
				logger(TAG, "VALIDATE GENERAL ERROR\t");
			}
			printf("Something went wrong with your input, try again.\n: ");
		}
		getItFlag = getIt(line, &length);
		if(log==1){
			if(getItFlag==1){
				logger(TAG, "GETIT PASS\t");
			}
		}
		validateFlag = validate(&a, &b, &c, line, length);
		if(log==1){
			if(validateFlag==1){
			
				logger(TAG, "VALIDATE PASS\t");
			
			}
		}
	}
	double result1, result2 = 0.0;
	int calculateFlag = calculate(a, b, c, &result1, &result2);
	if(calculateFlag != 1)
	{
		if(log==1){
				logger(TAG, "CALCULATE INF OR NAN INPUT\t");
		}
		printf("one of the input variables was an INF or NAN \n");
	}
	if(calculateFlag==1){
		if(log==1){
			logger(TAG, "CALCULATE PASS\t");
		}

	}
	char output[1000]= {0};
	int formatFlag = format(result1, result2, output);
	if(formatFlag != 1)
	{
		if(log==1){
			logger(TAG, "FORMAT UNKNOWN ERR\t");
		}
		printf("We don't know how this happened");
	}
	if(formatFlag==1){
		if(log==1){
			logger(TAG, "FORMAT PASS\t");
		}
	}
	int putItFlag = putIt(output);
	if(putItFlag != 1)
	{
		if(log==1){
			logger(TAG, "PUTIT NO OUTPUT\t");
		}
		printf("There was nothing to be output");
	}
	if(putItFlag==1){
		if(log==1){
			logger(TAG, "PUTIT PASS\t");
		}
	}
}//endfor
	return 0;
}
