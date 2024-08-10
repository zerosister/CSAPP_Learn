#include<stdio.h>
int a[4] = {-1,-2,2,3};
extern int val;
int sum();
int main(int argc, char *argv[]) {
  val = sum();
  printf("sum is %d\n", val);
}