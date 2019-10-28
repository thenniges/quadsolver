#include <stdlib.h>
#include <stdio.h>
#include "getIt.h"

#ifndef BUFLEN
#define BUFLEN 64
#endif

int main(int argc, char const *argv[]) {
  char *line = calloc(BUFLEN+2, sizeof(char));
  int linelen = BUFLEN;

  printf("%d %s", BUFLEN, ":");
  while (getIt(line, &linelen) == 1) {
    printf("%d %s\n", linelen, line);
    linelen = BUFLEN;
    printf("%d %s", BUFLEN, ":");
  }
  printf("\n");
  free(line);
  return 0;
}
