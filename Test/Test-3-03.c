#include "../Src/3-03func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_expand_basic(void) {
  char to_expand[1024] = "a-e";
  char expanded[1024] = {0};
  expand(to_expand, expanded);
  TEST_ASSERT_EQUAL_STRING("abcde", expanded);
}

void test_expand_no_expansion(void) {
  char to_expand[1024] = "abe";
  char expanded[1024] = {0};
  expand(to_expand, expanded);
  TEST_ASSERT_EQUAL_STRING("abe", expanded);
}

void test_expand_twice(void) {
  char to_expand[1024] = "a-e0-9";
  char expanded[1024] = {0};
  expand(to_expand, expanded);
  TEST_ASSERT_EQUAL_STRING("abcde0123456789", expanded);
}

void test_expand_leading(void) {
  char to_expand[1024] = "-a-e";
  char expanded[1024] = {0};
  expand(to_expand, expanded);
  TEST_ASSERT_EQUAL_STRING("-abcde", expanded);
}

void test_expand_trailing(void) {
  char to_expand[1024] = "a-e-h";
  char expanded[1024] = {0};
  expand(to_expand, expanded);
  TEST_ASSERT_EQUAL_STRING("abcde-h", expanded);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_expand_basic);
  RUN_TEST(test_expand_no_expansion);
  RUN_TEST(test_expand_twice);
  RUN_TEST(test_expand_leading);
  RUN_TEST(test_expand_trailing);
  return UNITY_END();
}
