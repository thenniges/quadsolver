/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <errno.h>
#include "validate.h"

int validate(double* a, double* b, double* c, char* line, int length)
{
	int ret = VLDT_ERR;
	float parsed = NAN;					// buffer for strtof() results
	char *endptr = NULL;				// required by strtof()
	char *oldptr = NULL;
	errno = 0;

	parsed = strtof(line, &endptr);		// try to parse a
	if (parsed == 0.0) {				// failed, set the error code
		if (endptr == line) {			// couldn't find a float
			ret = VLDT_ERR_FORMAT;
		} else if (errno == ERANGE) {	// input value is not normalized
			ret = VLDT_ERR_INPUT_RANGE;
		} else {						// a is 0, not allowed
			ret = VLDT_ERR_A_ZERO;
		}
	} else if ((parsed == NAN) || (parsed == INFINITY)) {
		ret = VLDT_ERR_INPUT_RANGE;		// also not allowed
	} else {							// a is ok
		*a = (double) parsed;
		oldptr = endptr;

		parsed = strtof(endptr, &endptr);	// try to parse b
		if (oldptr == endptr) {
			ret = VLDT_ERR_FORMAT;
		} else if ((errno == ERANGE) ||
			(parsed == NAN) || (parsed == INFINITY)) {
			ret = VLDT_ERR_INPUT_RANGE;
		} else {
			*b = (double) parsed;
			oldptr = endptr;

			parsed = strtof(endptr, &endptr);
			if (oldptr == endptr) {
				ret = VLDT_ERR_FORMAT;
			} else if ((errno == ERANGE) ||
				(parsed == NAN) || (parsed == INFINITY)) {
				ret = VLDT_ERR_INPUT_RANGE;
			} else if (sqrt(((*b)*(*b)) - 4*(*a)*(*c)) < 0) {
				ret = VLDT_ERR_RESULT_NAN;
			} else {
				*c = (double) parsed;
				ret = VLDT_SUCCESS;
			}
		}
	}

	return ret;
}
