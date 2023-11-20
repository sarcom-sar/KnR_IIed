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
