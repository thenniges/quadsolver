/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "calculate.h"
#include <math.h>

int calculate(double a, double b, double c, double* result1, double* result2)
{

  	float determinant;

 	//printf("Enter coefficients a, b and c: ");

 	//scanf("%f%f%f",&a,&b,&c);


  	determinant = b*b - 4*a * c;

  	if (determinant>0)
  	{
      	*result1 = (-b+sqrt(determinant))/(2*a);
      	*result2 = (-b-sqrt(determinant))/(2*a);
    	// printf("Roots are: %.2f and %.2f\n",r1 , r2);
  	}
  	else if (determinant==0)
  	{
    	*result1 = *result2 = -b/(2*a);
    	// printf("Roots are: %.2f and %.2f\n", r1, r2);
  	}
  	else if(a > 0.00000000 && a <0.00000001)
  	{
		*result1 = *result2 = INFINITY;
    	// real= -b/(2*a);
    	// imag = sqrt(-determinant)/(2*a);
    	// printf("Roots are: %.2f+%.2fi and %.2f-%.2fi\n", real, imag, real, imag);
	}
	else if(determinant < 0){
		*result1 = *result2 = NAN;
	}
	return 1;
}