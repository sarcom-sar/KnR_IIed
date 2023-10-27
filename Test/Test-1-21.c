#include "../Unity/unity.h"
#include "../Src/1-21func.c"


void setUp (void) {}
void tearDown (void) {}

void test_print_tabbed_normal(void) {
  char line_normal[] = "    test";
  print_tabbed(line_normal);
  TEST_ASSERT_EQUAL_STRING("\ttest", line_normal);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_print_tabbed_normal);
  return UNITY_END();
}
