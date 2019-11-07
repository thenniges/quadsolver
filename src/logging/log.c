/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <stdio.h>
#include <stdlib.h>
#include "logger.h"
#include <time.h>
#include <string.h>
#include <math.h>
#define TAG " TEST_STATUS  "
char *logger(const char *tag, const char *message);
// function takes in an integer an return success or failure print to a text log.
// int main(int argc, char *argv[])
// {
//     char *message;
//     char *total;
//     int ctn = 0;
//     int ok, lp;

//     printf("%d", lp);
//     switch (lp)
//     {
//     case 0:
//         message = malloc(sizeof(char) * 10);
//         strcpy(message, "success\t");
//         logger(TAG, message);
//         break;
//     default:
//         message = malloc(sizeof(char) * 10);
//         strcpy(message, "fail\t");
//         logger(TAG, message);
//         break;
//     }
//     return 0;
// }

char *logger(const char *tag, const char *message)
{
    FILE *f;
    // int count = 0;
    // time_t now;
    // char *hold[100];// this array stores logs messages to 100
    char *result = malloc(strlen(tag) + strlen(message) + 1);

    // time(&now);
    strncpy(result, TAG, sizeof(TAG));
    strncat(result, message, strlen(message));
    // char* time = (char *)ctime(&now);
    strncat(result, "\n", 2 );
    // hold[count] = result;

    // count++;
    f = fopen("logs.txt", "a+");
    // if (f != NULL)
    
    fprintf(f, result, 1);
    fclose(f);
    return result;
}
