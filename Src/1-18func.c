#include "1-18func.h"

void remove_trailing(char line[], int len) {
  int i = 0;
  for (i = len - 2; line[i] == ' ' || line[i] == '\t'; --i)
    ;
  line[i+1] = '\n';
  line[i+2] = '\0';
}
