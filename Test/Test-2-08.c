#include "../Src/2-08func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_right_rot_normal(void) {
  TEST_ASSERT_EQUAL_UINT(127, right_rot(254, 1));
  TEST_ASSERT_EQUAL_UINT(16, right_rot(128, 3));
  TEST_ASSERT_EQUAL_UINT(7, right_rot(14, 1));
}
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_right_rot_normal);
  return UNITY_END();
}
