#include <stdio.h>

void squeeze(char s[], char c[]);

int main(void) {
  char string[] = "AAAbbbCCCdddEEE";
  char to_remove[] = "CdAe";
  squeeze(string, to_remove);
  printf("%s\n", string);
  return 0;
}

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
