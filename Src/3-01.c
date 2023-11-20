#include <stdio.h>
#include "3-01func.h"

#define ARR_LEN 5

int main(void) {
  int arr[ARR_LEN] = {1, 2, 3, 4, 5};
  printf("SLOW %d in array [ ", 5);
  for (int i = 0; i < ARR_LEN; i++)
    printf("%d ", arr[i]);
  int result = binsearch_slow(5, arr, ARR_LEN);
  (result == -1) ? printf("] wasn't found\n")
                 : printf("] is at position %d\n", result);

  printf("SLOW %d in array [ ", 3);
  for (int i = 0; i < ARR_LEN; i++)
    printf("%d ", arr[i]);
  result = binsearch_slow(3, arr, ARR_LEN);
  (result == -1) ? printf("] wasn't found\n")
                 : printf("] is at position %d\n", result);

  printf("FAST %d in array [ ", 5);
  for (int i = 0; i < ARR_LEN; i++)
    printf("%d ", arr[i]);
  result = binsearch_fast(5, arr, ARR_LEN);
  (result == -1) ? printf("] wasn't found\n")
                 : printf("] is at position %d\n", result);

  printf("FAST %d in array [ ", 3);
  for (int i = 0; i < ARR_LEN; i++)
    printf("%d ", arr[i]);
  result = binsearch_fast(3, arr, ARR_LEN);
  (result == -1) ? printf("] wasn't found\n")
                 : printf("] is at position %d\n", result);
  return 0;
}
