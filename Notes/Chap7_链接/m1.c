#include <stdio.h>
int a1 ; 
int a2 = 2 ; 
extern int a4 ; 
void hello() 
{ 
printf("%p;", &a1); 
printf("%p;", &a2); 
printf("%p\n", &a4);
}