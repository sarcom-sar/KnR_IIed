#include "1-19func.h"

int reverse_line(char line[], int len) {
  int i = 0;
  int x = 0;
  char reversed[len+1];

  while (line[i] != '\n') ++i;

  for (i = i - 1; i >= 0; --i) {
    reversed[x] = line[i];
    x++;
  }
  reversed[x] = '\n';
  reversed[x + 1] = '\0';

  while (i < (x + 1)) {
    line[i] = reversed[i];
    i++;
  }
  return 0;
}
