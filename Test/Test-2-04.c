#include "../Src/2-04func.c"
#include "../Unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_squeeze_normal(void) {
  char change[] = "BBccAcAcA";
  char what_del[] = "AB";
  squeeze(change, what_del);
  TEST_ASSERT_EQUAL_STRING("cccc", change);
}

void test_squeeze_nothing_to_delete(void) {
  char change[] = "BBccAcAcA";
  char what_del[] = "Z";
  squeeze(change, what_del);
  TEST_ASSERT_EQUAL_STRING("BBccAcAcA", change);
}

void test_squeeze_delete_all(void) {
  char change[] = "BBccAcAcA";
  char what_del[] = "BcA";
  squeeze(change, what_del);
  TEST_ASSERT_EQUAL_STRING("", change);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_squeeze_normal);
  RUN_TEST(test_squeeze_nothing_to_delete);
  RUN_TEST(test_squeeze_delete_all);
  return UNITY_END();
}
