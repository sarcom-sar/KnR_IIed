#include "3-03func.h"
#include <string.h>

void expand(char s1[], char s2[]) {
  int x = 1;
  int temp1 = 0;
  int temp2 = 0;
  int len = strlen(s1);

  // pre-append, because `-` can't be a valid 0th char anyway
  s2[0] = s1[0];

  for (int i = 1; i < len; i++) {
    if (s1[i] == '-') {
      if (!is_valid_char(s1[i - 1])) {
        s2[x++] = s1[i];
        continue;
      }
      if (!is_valid_char(s1[i + 1])) {
        s2[x++] = s1[i];
        continue;
      }
      temp1 = s1[i - 1];
      temp2 = s1[i + 1];
      if ((temp1 - temp2) < 0) {
        temp1++;
        while (temp1 != temp2) {
          if (is_valid_char(temp1)) {
            s2[x] = temp1;
            x++;
          }
          temp1++;
        }
      } else {
        temp1--;
        while (temp1 != temp2) {
          if (is_valid_char(temp1)) {
            s2[x] = temp1;
            x++;
          }
          temp1--;
        }
      }
    } else {
      s2[x] = s1[i];
      x++;
    }
  }
}

int is_valid_char(int chr) {
  return (chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z') ||
         (chr >= '0' && chr <= '9');
}
