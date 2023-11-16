#include <stdio.h>

int lower(int c);

int main(void) {
  printf("letter %c is upper case of %c\n", 'A', lower('A'));
  printf("letter %c is already lower case of %c\n", 'a', lower('a'));
  printf("letter %c is upper case of %c\n", 'Z', lower('Z'));
  printf("letter %c is already lower case of %c\n", 'z', lower('z'));
  return 0;
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
