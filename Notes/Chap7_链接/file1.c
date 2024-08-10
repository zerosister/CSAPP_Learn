#include <stdio.h>
void shit() {
  printf("Hello world!\n");
}
// 下面的情况会找不到 shit 函数
// static void shit() {
//   printf("Hello world!\n");
// }