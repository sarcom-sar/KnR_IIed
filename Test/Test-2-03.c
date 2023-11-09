#include "../Src/2-03func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_sqrt_q(void) {
  TEST_ASSERT_EQUAL_INT(-1, sqrt_q(5, -1));
  TEST_ASSERT_EQUAL_INT(1, sqrt_q(5, 0));
  TEST_ASSERT_EQUAL_INT(25, sqrt_q(5, 2));
}

void test_htoi(void) {
  // valid inputs
  TEST_ASSERT_EQUAL_INT(241, htoi("0xF1\n"));
  TEST_ASSERT_EQUAL_INT(241, htoi("0xf1\n"));
  TEST_ASSERT_EQUAL_INT(1, htoi("0x1\n"));

  // valid but not at the start
  TEST_ASSERT_EQUAL_INT(1, htoi("what do you want 0x1\n"));

  // invalid inputs
  TEST_ASSERT_EQUAL_INT(-1, htoi("abcd\n"));
  TEST_ASSERT_EQUAL_INT(-1, htoi("ab0cd\n"));
  TEST_ASSERT_EQUAL_INT(-1, htoi("ab0xgh\n"));
  TEST_ASSERT_EQUAL_INT(-1, htoi("\n"));
  TEST_ASSERT_EQUAL_INT(-1, htoi(""));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_sqrt_q);
  RUN_TEST(test_htoi);
  return UNITY_END();
}
