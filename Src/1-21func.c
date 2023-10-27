#include "1-21func.h"
#include <stdio.h>

#define TAB 4

int print_tabbed(char line[]) {
  int spc_max = 0;
  for (int i = 0; line[i] != '\0'; i++) {
    if (line[i] == ' ') {
      spc_max++;
    } else {
      while (spc_max >= TAB) {
        putchar('\t');
        spc_max -= TAB;
      }
      while (spc_max > 0) {
        putchar(' ');
        spc_max--;
      }
      if (spc_max <= 0)
        spc_max = 0;
      if (spc_max == 0)
        putchar(line[i]);
    }
  }
  return 0;
}
