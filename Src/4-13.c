#include <stdio.h>
#include <string.h>

void reverse(char *s, int l, int r) {
  int temp;
  if (l < r) {
    reverse(s, l+1, r-1);
    temp = s[l];
    s[l] = s[r];
    s[r] = temp;
  }
}
int main(void) {
  char s[] = "I am a nice string";
  reverse(s, 0, strlen(s)-1);
  printf("%s\n", s);
}
