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
	if(isnan(result1)!=0){
		strncpy(result1String, "nan ", 5);
	}
	else if(isinf(result1)!=0){
		if(signbit(result1) == 0)
		{
			strncpy(result1String, "inf ", 5);
		}
		else
		{
			strncpy(result1String, "-inf ", 6);
		}
	}
	else{
		sprintf(result1String, "%e", result1);
		strncat(result1String, " ", 2);
	}
	if(isnan(result2)!=0){
		strncpy(result2String, "nan.", 5);
	}
	else if(isinf(result2)!=0){
		if(signbit(result1) == 0)
		{
			strncpy(result2String, "inf.", 5);
		}
		else
		{
			strncpy(result2String, "-inf.", 6);
		}
	}
	else{
		sprintf(result2String, "%e", result2);
		strncat(result2String, ".", 2);
	}

	strncpy(output, "The roots of this function are ", 32);
	strncat(output, result1String, sizeof(result1String));

	strncat(output, "and ", 5);
	strncat(output, result2String, sizeof(result2String));
	strncat(output, "\n", 2);

	return 1;
}
