#include "../Src/3-01func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_binsearch_slow(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  TEST_ASSERT_EQUAL_INT(4, binsearch_slow(5, arr, 5));
  TEST_ASSERT_EQUAL_INT(2, binsearch_slow(3, arr, 5));
}

void test_binsearch_fast(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  TEST_ASSERT_EQUAL_INT(4, binsearch_fast(5, arr, 5));
  TEST_ASSERT_EQUAL_INT(2, binsearch_fast(3, arr, 5));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_binsearch_slow);
  RUN_TEST(test_binsearch_fast);
  return UNITY_END();
}
