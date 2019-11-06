/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "calculate.h"
#include <stdio.h>
#include <math.h>

int calculate(double a, double b, double c, double* result1, double* result2)
{
	if( isnan(a) || isnan(b) || isnan(c)){
		return -1;
	}
	if( isinf(a) || isinf(b) || isinf(c)){
		return -1;
	}
  	double determinant;

  	determinant = b*b - 4*a * c;

  	if (determinant>0)
  	{
      	*result1 = (-b+sqrt(determinant))/(2*a);
      	*result2 = (-b-sqrt(determinant))/(2*a);
  	}
  	else if (determinant==0)
  	{
    	*result1 = *result2 = -b/(2*a);
  	}
  	else if(a > -0.00001 && a < 0.00001)
  	{
		  *result1 = *result2 = INFINITY;
    }
	 else if(determinant < 0){
      *result1 = *result2 = NAN;
    }

    if((*result1) > (*result2))
    {
      double temp = *result1;
      *result1 = *result2;
      *result2 = temp;
    }

	return 0;
}
