/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "format.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int format(double result1, double result2, char* output)
{
	if(isnormal(result1)<0 || isnormal(result2) < 0){
		return-1;
	}
	char  result1String[80];
	char  result2String[80];
	char * startOfOutput = "The roots of this function are ";
	if(isnan(result1)!=0){
		printf("nan");
		strcpy(result1String, "nan ");
	}
	else if(isinf(result1)!=0){
		printf("inf");
		strcpy(result1String, "inf ");
	}
	else{
		printf("real number");
		gcvt(result1, 5, result1String);
		strcat(result1String, " ");
	}
	if(isnan(result2)!=0){
		printf("nan");
		strcpy(result2String, "nan.");
	}
	else if(isinf(result2)!=0){
		printf("inf");
		strcpy(result2String, "inf.");
	}
	else{
		printf("real number");
		gcvt(result2, 5, result2String);
		strcat(result2String, ".");
	}
	strcpy(output, startOfOutput);
	strcat(output, result1String);
	strcat(output, "and ");
	strcat(output, result2String);
	// strcat(output, result1String);
	// strcat(output, result2String);
	return 1;
}

// int main(int argc, char* argv[]){
// 	char output[62];
// 	// output[0] = '\0';
// 	format(INFINITY, NAN, output);
// 	printf("\n%s",output);
// 	return 1;
// }