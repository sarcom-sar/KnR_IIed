#include "../Src/2-10func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_lower_normal(void) {
  TEST_ASSERT_EQUAL_INT('a', lower('A'));
  TEST_ASSERT_EQUAL_INT('z', lower('Z'));
  TEST_ASSERT_EQUAL_INT('g', lower('G'));
}

void test_lower_low_char(void) {
  TEST_ASSERT_EQUAL_INT('a', lower('a'));
  TEST_ASSERT_EQUAL_INT('z', lower('z'));
  TEST_ASSERT_EQUAL_INT('g', lower('g'));
}

void test_lower_invalid(void) {
  TEST_ASSERT_EQUAL_INT(999, lower(999));
  TEST_ASSERT_EQUAL_INT(2135, lower(2135));
  TEST_ASSERT_EQUAL_INT(-999, lower(-999));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_lower_normal);
  RUN_TEST(test_lower_low_char);
  RUN_TEST(test_lower_invalid);
  return UNITY_END();
}
