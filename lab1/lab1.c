#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  printf("Please enter some text: ");

  char *lineptr = NULL;
  size_t len = 0;

  ssize_t line = getline(&lineptr, &len, stdin);

  if (line == -1) {
    perror("getline failed");
    exit(EXIT_FAILURE);
  }

  char *saveptr = NULL;
  char *ret = strtok_r(lineptr, " ", &saveptr);

  printf("Tokens: \n%s\n", ret);
  while ((ret = strtok_r(NULL, " ", &saveptr))) {
    printf("%s\n", ret);
  }

  free(lineptr);
  return 0;
}
