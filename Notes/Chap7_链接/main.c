#include<stdio.h>
double x=-1.5;
short y=1,z=2;
void procl(void);
void main(){
  z = *(((short*)&x) + 2);
  printf("x=%u,z=%d\n",x,z);
  for (int i=0; i<8; i++) {
    printf("0x%x\n", *((char*)&x + i));
  }
  return;
}
