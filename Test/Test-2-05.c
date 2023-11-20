#include "../Src/2-05func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_any_normal(void) {
  char string[] = "AAAbbbCCCdddEEE";
  char to_find[] = "ECb";
  TEST_ASSERT_EQUAL_INT(3, any(string, to_find));
}

void test_any_nothing_to_find(void) {
  char string[] = "AAAbbbCCCdddEEE";
  char to_find[] = "ecB";
  TEST_ASSERT_EQUAL_INT(-1, any(string, to_find));
}

void test_any_empty_find(void) {
  char string[] = "AAAbbbCCCdddEEE";
  char to_find[] = "";
  TEST_ASSERT_EQUAL_INT(-1, any(string, to_find));
}

void test_any_empty_string(void) {
  char string[] = "";
  char to_find[] = "a";
  TEST_ASSERT_EQUAL_INT(-1, any(string, to_find));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_any_normal);
  RUN_TEST(test_any_nothing_to_find);
  RUN_TEST(test_any_empty_find);
  RUN_TEST(test_any_empty_string);
  return UNITY_END();
}
