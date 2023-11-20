#include "2-05func.h"
#include <string.h>

int any(char s[], char c[])
{
  int earliest = strlen(s);
  int is_found = 0;
  for (int x = 0; c[x] != '\0'; x++) {
    for (int i = 0; s[i] != '\0'; i++) {
      if (s[i] == c[x])
        if (earliest > i) {
          is_found = 1;
          earliest = i;
        }
    }
  }
  if (is_found)
    return earliest;
  return -1;
}
