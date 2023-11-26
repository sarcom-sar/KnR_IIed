#include "3-03func.h"

void expand(char s1[], char s2[]) {
  int x = 1;
  int temp1 = 0;
  int temp2 = 0;
  s2[0] = s1[0];

  for (int i = 1; s1[i] != '\0'; i++) {
    if (s1[i] == '-') {
      temp1 = s1[i-1];
      temp2 = s1[i+1];
      if ((temp1 - temp2) < 0) {
        temp1++;
        while (temp1 != temp2) {
          s2[x] = temp1;
          x++;
          temp1++;
        }
      } else {
        temp1--;
        while (temp1 != temp2) {
          s2[x] = temp1;
          x++;
          temp1--;
        }
      }
    } else {
      s2[x] = s1[i];
      x++;
    }
  }
}
