#include "1-20func.h"
#include <stdio.h>

#define TAB 4

int print_tabless(char line[]) {
  for (int i = 0; line[i] != '\0'; ++i) {
    if (line[i] == '\t') {
      for (int x = 0; x < TAB; x++)
        putchar(' ');
    } else {
      putchar(line[i]);
    }
  }

  return 0;
}
