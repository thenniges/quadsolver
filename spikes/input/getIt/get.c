#include <stdlib.h>
#include <stdio.h>
#include "getIt.h"

#ifndef BUFLEN
#define BUFLEN 65
#endif

int main(int argc, char const *argv[]) {
  char *line = calloc(BUFLEN, sizeof(char));
  int linelen = BUFLEN;

  printf("%d %s", BUFLEN-1, ":");
  while (getIt(line, &linelen) == 1) {
    printf("%d %s\n", linelen, line);
    linelen = BUFLEN;
    printf("%d %s", BUFLEN-1, ":");
  }
  printf("\n");
  free(line);
  return 0;
}
