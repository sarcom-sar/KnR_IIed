#include "../Unity/unity.h"
#include "../Src/1-18func.c"


void setUp (void) {}
void tearDown (void) {}

void test_remove_trailing_normal(void) {
  char line_normal[] = "test\n";
  remove_trailing(line_normal, 5);
  TEST_ASSERT_EQUAL_STRING("test\n", line_normal);
}

void test_remove_trailing_trailing_space(void) {
  char line_trailing[] = "test   ";
  remove_trailing(line_trailing, 7);
  TEST_ASSERT_EQUAL_STRING("test\n", line_trailing);
}

void test_remove_trailing_trailing_tab(void) {
  char line_trailing[] = "test\t\t";
  remove_trailing(line_trailing, 6);
  TEST_ASSERT_EQUAL_STRING("test\n", line_trailing);
}

void test_remove_trailing_inner_trailing(void) {
  char line_trailing[] = "te   st";
  remove_trailing(line_trailing, 8);
  TEST_ASSERT_EQUAL_STRING("te st\n", line_trailing);
}

void test_remove_trailing_before_trailing(void) {
  char line_trailing[] = "   test";
  remove_trailing(line_trailing, 8);
  TEST_ASSERT_EQUAL_STRING("test\n", line_trailing);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_remove_trailing_normal);
  RUN_TEST(test_remove_trailing_trailing_space);
  RUN_TEST(test_remove_trailing_trailing_tab);
  RUN_TEST(test_remove_trailing_inner_trailing);
  RUN_TEST(test_remove_trailing_before_trailing);
  return UNITY_END();
}
