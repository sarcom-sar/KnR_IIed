#include <stdio.h>
#include <string.h>

#define SWAP(t, x, y) do { t temp = x; x = y; y = temp; } while(0);

int main(void) {
  int a = 10;
  int b = 25;
  printf("Pre-swap\na = %d\nb = %d\n", a, b);
  SWAP(int, a, b);
  printf("Post-swap\na = %d\nb = %d\n", a, b);
}
