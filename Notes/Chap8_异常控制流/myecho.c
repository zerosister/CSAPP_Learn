#include <stdio.h>
#include <stdlib.h>

extern char** environ;

int main(int argc, char* argv[]) {
  printf("Command Lines:\n");
  for (int i = 0; i < argc; i++) {
    printf("argv[%d]: %s\n", i, argv[i]);
  }
  printf("Environment variables:\n");
  int i = 0;
  char *env = environ[i];
  while (env != NULL) {
    printf("envp[%d]:%s\n", i, env);
    i++;
    env = environ[i];
  }
  return 0;
}