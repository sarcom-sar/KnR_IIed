#include "../Src/2-07func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_invert_normal(void) {
  TEST_ASSERT_EQUAL_UINT(241, invert(255, 3, 3));
  TEST_ASSERT_EQUAL_UINT(4, invert(10, 3, 3));
  TEST_ASSERT_EQUAL_UINT(15, invert(14, 0, 1));
}
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_invert_normal);
  return UNITY_END();
}
