/*
Copyright 2019 Blacktop Group

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// pull in user input char-at-a-time to limit possible input.

#include <stdio.h>
#include <stdlib.h>

int getIt(char* line, int* length)
{
  printf("%s\n", "Enter a:"); // use ansi escape to bold 'a'?
  int count = length[0];
  char buffer = 0;
  for (size_t i = 0; i < count+1; i++) {
    if (i >= count) {
      printf("\n%s\n",
        "Error: input is limited to 20 characters and 4 significant digits.");
      printf("%s\n", "\tConsider using scientific notation (nEx = n * 10^x) ");
    }

    buffer = (char) fgetc(stdin);
    printf("%ld: %c\n", i, buffer);
    // is it a digit?
    int e = 0;
    int point = 0;
    int hyphen_index = 0;   // the allowable position for a hyphen_index
    int there_has_been_a_number = -1;
    switch (buffer) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        /* yay */
        there_has_been_a_number = 0;
        break;
      case '.':
        if (point == 0) {
          point = -1;
          break;
        } else {
          printf("\n%s\n", "Error: only one decimal point is allowed.");
          return -1;
        }
        break;
      case '-':
        if (i != hyphen_index) {
          printf("%s\n", "Error: \'-\' is only allowed as the first ");
          return -1;
        }
        break;
      case 'e':
      case 'E':
        if ((e == 0) && (there_has_been_a_number == 0)) {
          e = -1;
          hyphen_index = i+1;
          there_has_been_a_number = -1;
          break;
        } else {
          printf("\n%s\n", "Error: only one \'e\' is allowed.");
          return -1;
        }
        break;
      default:
        return -1;
        break;
    }
    line[i] = buffer;
  }
  printf("%s\n", line);
	return 0;
}

int main(int argc, char const *argv[]) {
  int* length = calloc(3, sizeof(int));
  length[0] = 20;
  length[1] = 20;
  length[2] = 20;
  char* line = "i am initialized now";
  printf("%s\n", line);
  // char* line = calloc(length[0], sizeof(char));
  getIt(line, length);

  free(length);
  free(line);
  return 0;
}
