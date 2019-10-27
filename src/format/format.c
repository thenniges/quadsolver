/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#define _DEFAULT_SOURCE
#include "format.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int format(double result1, double result2, char* output)
{
	
	char  result1String[80];
	char  result2String[80];
	// char * startOfOutput = ;
	if(isnan(result1)!=0){
		// printf("nan");
		strncpy(result1String, "nan ", 5);
	}
	else if(isinf(result1)!=0){
		// printf("inf");
		strncpy(result1String, "inf ", 5);
	}
	else{
		// printf("real number");
		gcvt(result1, 5, result1String);
		strncat(result1String, " ", 2);
	}
	if(isnan(result2)!=0){
		// printf("nan");
		strncpy(result2String, "nan.", 5);
	}
	else if(isinf(result2)!=0){
		// printf("inf");
		strncpy(result2String, "inf.", 5);
	}
	else{
		// printf("real number");
		gcvt(result2, 5, result2String);
		strncat(result2String, ".", 2);
	}
	// char* startOfOutput = "The roots of this function are ";
	// int i;
	// for(i = 0 ; i < strlen(startOfOutput) ;i++){
	// 	output[i] = startOfOutput[i];
	// }output[i] = '\0';

	strncpy(output, "The roots of this function are ", 32);
	strncat(output, result1String, sizeof(result1String));
	
	strncat(output, "and ", 5);
	strncat(output, result2String, sizeof(result2String));
	
	// strcat(output, result1String);
	// strcat(output, result2String);
	return 1;
}

// int main(int argc, char* argv[]){
// 	char *output = calloc(62, sizeof(char));
// 	// output[0] = '\0';
// 	format(INFINITY, .123, output);
// 	printf("\n%s",output);
// 	return 1;
// }