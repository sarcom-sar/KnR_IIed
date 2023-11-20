#include "../Src/2-09func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_bitcount_slow(void) {
  TEST_ASSERT_EQUAL_UINT(1, bitcount_slow(1));
  TEST_ASSERT_EQUAL_UINT(8, bitcount_slow(255));
  TEST_ASSERT_EQUAL_UINT(5, bitcount_slow(2137));
}

void test_bitcount_fast(void) {
  TEST_ASSERT_EQUAL_UINT(1, bitcount_fast(1));
  TEST_ASSERT_EQUAL_UINT(8, bitcount_fast(255));
  TEST_ASSERT_EQUAL_UINT(5, bitcount_fast(2137));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_bitcount_slow);
  RUN_TEST(test_bitcount_fast);
  return UNITY_END();
}
