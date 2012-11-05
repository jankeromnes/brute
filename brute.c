#include <stdio.h>

#define FORK 0

void print(char * t[], int from, int to) {
  int i;
  for (i = from ; i < to ; i++) {
    printf("%s ", t[i]);
  }
  printf("\n");
}

void swap(char * t[], int i, int j) {
  char * tmp = t[i];
  t[i] = t[j];
  t[j] = tmp;
}

main (int argc, char * argv[]) {

  int n = argc - 1;
  int stack[64] = {0};
  int esp = n - 1;
  int stop = 0;
  int offset = 0;
  int odd = 0;

  if (n < 1 || n > 64) {
    printf("usage: %s <sequence>\n", argv[0]);
    return 0;
  }

  for (stop = 0; stop < FORK; stop++) {
    if (fork()) {
      swap(argv, 1, 2);
    }
  }

  print(argv, 1, argc);

  while (esp > stop) {

    if (stack[esp] < esp) {

      odd = (stack[esp] + (esp + 1) * stack[esp - 1]) % 2;

      if ((esp < n - 1) && ((odd + 1) % 2)) {
        offset = 1 + (esp < n - 2) * ((esp + 2) % 2);
      } else {
        offset = 0;
      }

      odd = (stack[esp-1] + esp * (esp > 1 ? stack[esp - 2] : 0)) % 2;

      if (odd) {
        swap(argv, offset + stack[esp] + 1, offset + stack[esp] + 2);
      } else {
        swap(argv, offset + esp - stack[esp], offset + esp - stack[esp] + 1);
      }
      print(argv, 1, argc);

      stack[esp]++;
      if (esp <  n - 1) {
        esp = n - 1;
      }

    } else {
      stack[esp] = 0;
      esp--;
    }
  }

  return 0;
}
