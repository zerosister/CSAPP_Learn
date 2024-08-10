#include <stdio.h>
int main() {
  int i = 12345;
  float f = 1.2345e3;
  printf("the answer is %d\n", (int)(double)i == i);
  printf("the answer is %d\n", (int)(float)i == i);
  printf("the answer is %f\n", (float)(int)f == f);
  printf("the answer is %d\n", (float)(double)f == f);

  long max = -1;
  // unsigned int half = 0x80000000;
  unsigned int half = 0x80000003u;
  printf("now max + half is %d or %lu\n", half+max, max); // 将 half 隐式地转化为了 int

  max = -7;
  printf("%x\n", max);

  long p;
  unsigned hp;
  p = -2;
  hp = (unsigned)p;
  printf("p is %p, hp is %p\n", p, hp);

  short x = -17231;
  printf("x is %x, x/64 is %x\n", x, x/64);

  {
    int x = 53191;
    short sx = (short)x;
    int y = sx;
    printf("x is %d,sx is %d, y is %d\n", x, sx, y);
  }
}