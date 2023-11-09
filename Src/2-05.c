#include <stdio.h>
#include <string.h>

int any(char s[], char c[]);

int main(void) {
  char string[] = "AAAbbbCCCdddEEE";
  char to_find1[] = "ECb";
  printf("expected value 3, actual value %d\n", any(string, to_find1));

  char to_remove2[] = "ecB";
  printf("expected value -1, actual value %d\n", any(string, to_remove2));

  char to_remove3[] = "";
  printf("expected value -1, actual value %d\n", any(string, to_remove3));

  char string_empty[] = "";
  char to_remove4[] = "a";
  printf("expected value -1, actual value %d\n", any(string_empty, to_remove4));
  return 0;
}

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
