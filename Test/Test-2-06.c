#include "../Src/2-06func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_setbits_normal(void) {
  TEST_ASSERT_EQUAL_UINT(243, setbits(255, 3, 3, 1));
  TEST_ASSERT_EQUAL_UINT(90, setbits(170, 7, 4, 85));
  TEST_ASSERT_EQUAL_UINT(254, setbits(238, 4, 1, 17));
}
int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_setbits_normal);
  return UNITY_END();
}
