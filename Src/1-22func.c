#include "1-22func.h"

#define MAXLEN 80

int break_line(char line[]) {
  int point = 0;
  int new_i = 0;
  for (int i = 0; line[i] != '\0'; i++) {
    if (line[i] == ' ' || line[i] == '\t') {
      point = i;
    }
    if (new_i > MAXLEN) {
      if (point != 0)
        line[point] = '\n';
      point = 0;
      new_i = 0;
    }
    new_i++;
  }
  return 0;
}
