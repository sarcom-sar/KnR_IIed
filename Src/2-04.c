#include <stdio.h>
#include "2-04func.h"

int main(void) {
  char string[] = "AAAbbbCCCdddEEE";
  char to_remove[] = "CdAe";
  squeeze(string, to_remove);
  printf("%s\n", string);
  return 0;
}
