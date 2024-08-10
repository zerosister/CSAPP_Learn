#include <stdio.h>
int main () {
  struct non {
    char c;
    long n;
    int k;
    float *p;
    short a;
  };
  printf("\nsize of non is %d\n", sizeof(long));
  return 0;
}