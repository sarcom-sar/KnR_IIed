#include "../Unity/unity.h"
#include "../Src/1-16func.h"

void setUp (void) {}
void tearDown (void) {}

void test_getaline(void) {
  TEST_ASSERT_EQUAL_FLOAT(1.0, 1.0);
}

void test_copy(void) {
  TEST_ASSERT_EQUAL_FLOAT(1.0, 1.0);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_getaline);
  RUN_TEST(test_copy);
  return UNITY_END();
}
