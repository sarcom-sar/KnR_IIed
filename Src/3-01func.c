#include "3-01func.h"

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

