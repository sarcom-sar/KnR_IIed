#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void itoa(int n, char s[], int padding);
void reverse(char s[]);

int main(void) {
  char s[MAX] = {0};
  itoa(256, s, 4);
  printf("%s\n", s);

  char z[MAX] = {0};
  itoa(-256, z, 4);
  printf("%s\n", z);
}

void itoa(int n, char s[], int padding) {
  int i;
  int sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  while (i < padding) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
