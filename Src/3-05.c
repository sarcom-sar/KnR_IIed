#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(void) {
  char s[MAX] = {0};
  itob(255, s, 10);
  printf("%s\n", s);

  char x[MAX] = {0};
  itob(255, x, 8);
  printf("%s\n", x);

  char z[MAX] = {0};
  itob(255, z, 16);
  printf("%s\n", z);
}

void itob(int n, char s[],int base) {
  int i;
  int sign = n;

  i = 0;
  do {
    int num = abs(n % base);
    if (num >= 10) {
      num += ('A' - 10);
    } else {
      num += '0';
    }
    s[i++] = num;
  } while ((n /= base) != 0);
  if (sign < 0)
    s[i++] = '-';
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
