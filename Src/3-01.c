#include <stdio.h>

#define ARR_LEN 5

int binsearch_slow(int x, int v[], int n);
int binsearch_fast(int x, int v[], int n);

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

int binsearch_slow(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid + 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid; // match
  }
  return -1; // no match
}

int binsearch_fast(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x > v[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }

  if (x == v[mid]) return mid;
  if (x == v[low]) return low;
  if (x == v[high]) return high;

  return -1;
}
