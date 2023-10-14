#include "../Unity/unity.h"

#define getchar mockchar
char *mockchar_data;
char mockchar() {
  return *mockchar_data++;
}

#include "../Src/1-16func.c"


void setUp (void) {}
void tearDown (void) {}

void test_getaline_normal(void) {
  char a[50];

  mockchar_data = "hello\n";
  TEST_ASSERT_EQUAL_INT(6, getaline(a, 50));
}

void test_getaline_empty(void) {
  char a[50];

  mockchar_data = "\n";
  TEST_ASSERT_EQUAL_INT(1, getaline(a, 50));
}

void test_getaline_very_long(void) {
  char a[5];

  mockchar_data = "abcdefghijklmnoprstow";
  TEST_ASSERT_EQUAL_INT(4, getaline(a, 5));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_getaline_normal);
  RUN_TEST(test_getaline_empty);
  RUN_TEST(test_getaline_very_long);
  return UNITY_END();
}
