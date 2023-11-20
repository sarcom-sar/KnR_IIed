#include "2-04func.h"

void squeeze(char s[], char c[])
{
  int i, j;
  for (int x = 0; c[x] != '\0'; x++) {
    for (i = j = 0; s[i] != '\0'; i++)
      if (s[i] != c[x])
        s[j++] = s[i];
    s[j] = '\0';
  }
}
