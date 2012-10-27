#include <stdio.h>
#include <time.h>

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

  //clock_t begin, end;

  int n = argc - 1;
  int i = 0, j = 0, k = 0;
  int stack[32] = {0};
  int esp = n - 1;
  int stop = 0;
  int count = 0;
  int offset = 0;
  int odd = 0;

  if (n < 1) {
    printf("usage: %s <sequence>\n", argv[0]);
    return 0;
  }

  //begin = clock();

  print(argv, 1, argc);

  while (esp > stop) {

    if (stack[esp] < esp) {

      //offset = (1 - ((count + stack[esp]) % 2)) * (n - 1 - esp);
      /*if ((esp < n - 1) && ((count + stack[esp] + 1) % 2)) {
        offset = 1 + (esp < n - 2) * ((esp + 2) % 2);
      } else {
        offset = 0;
      }*/

      odd = (stack[esp] + (esp + 1) * stack[esp - 1]) % 2;

      if ((esp < n - 1) && ((odd + 1) % 2)) {
        offset = 1 + (esp < n - 2) * ((esp + 2) % 2);
      } else {
        offset = 0;
      }

      odd = (stack[esp-1] + esp * (esp > 1 ? stack[esp - 2] : 0)) % 2;

      //if (count % 2) {
      if (odd) {
        swap(argv, offset + stack[esp] + 1, offset + stack[esp] + 2);
      } else {
        swap(argv, offset + esp - stack[esp], offset + esp - stack[esp] + 1);
      }
      printf("[P %d, S %d, C %d, O %d, O %d] - ", esp, stack[esp], count, odd, offset);
      print(argv, 1, argc);

      stack[esp]++;
      if (esp <  n - 1) {
        count += stack[esp];
        esp = n - 1;
      }
    } else {
      stack[esp] = 0;
      esp--;
      count -= stack[esp];
    }
  }

  //end = clock();
  //printf("Generated in %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

  return 0;
}
