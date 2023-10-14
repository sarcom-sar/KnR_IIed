#include "../Unity/unity.h"
#include "../Src/1-15func.c"

void setUp(void) {}
void tearDown(void) {}

void test_conversion_positive_values(void) {
  TEST_ASSERT_EQUAL_FLOAT(0.0, conversion(32));
  TEST_ASSERT_EQUAL_FLOAT(300.0, conversion(572));
  TEST_ASSERT_EQUAL_FLOAT(148.8889, conversion(300));
}

void test_conversion_negative_values(void) {
  TEST_ASSERT_EQUAL_FLOAT(-18.33333, conversion(-1));
  TEST_ASSERT_EQUAL_FLOAT(-295.5555, conversion(-500));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_conversion_positive_values);
  RUN_TEST(test_conversion_negative_values);
  return UNITY_END();
}
