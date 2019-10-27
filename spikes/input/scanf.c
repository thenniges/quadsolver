#include <stdio.h>
#include <float.h>

int main(int argc, char const *argv[]) {

  float a = 0;
  printf("%s", "input float: ");
  if (scanf("%e", &a) != 0) {
    printf("float: %.4e\n", a);
  } else {
    printf("%s\n", "not a float.");
  }

  return 0;
}
