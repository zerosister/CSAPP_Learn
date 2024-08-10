#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

unsigned int snooze(unsigned int secs) {
  unsigned int left = sleep(secs);
  printf("Slept for %d of %d secs\n", secs - left, secs);
  return left;
}

void sigint_handler(int sig) {
  printf("\nCaught SIGINT!\n");
}

int main(int argc, char** argv) {
  // 注册信号处理程序
  if (signal(SIGINT, sigint_handler) == SIG_ERR) 
    fprintf(stderr, "signal error\n");
  if (argc == 1) {
    snooze(2);
  }
  else snooze(atoi(argv[1]));
  return 0;
}