#include "../Unity/unity.h"
#include "../Src/1-20func.c"


void setUp (void) {}
void tearDown (void) {}

void test_print_tabless_normal(void) {
  char line_normal[] = "t\t\test\n";
  print_tabless(line_normal);
  TEST_ASSERT_EQUAL_STRING("t        est\n", line_normal);
}

void test_print_tabless_empty(void) {
  char line_empty[] = "\n";
  print_tabless(line_empty);
  TEST_ASSERT_EQUAL_STRING("\n", line_empty);
}

void test_print_tabless_singular_tab(void) {
  char singular_tab[] = "\t\n";
  print_tabless(singular_tab);
  TEST_ASSERT_EQUAL_STRING("    \n", singular_tab);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_print_tabless_normal);
  RUN_TEST(test_print_tabless_empty);
  RUN_TEST(test_print_tabless_singular_tab);
  return UNITY_END();
}
