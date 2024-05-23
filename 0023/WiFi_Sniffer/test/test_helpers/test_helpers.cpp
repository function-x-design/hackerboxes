#include "unity.h"
#include "helpers.hpp"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

    // 5. High quality: 90% ~= -55db
    // 4. Good quality: 75% ~= -65db
    // 3. Medium quality: 50% ~= -75db
    // 2. Low quality: 30% ~= -85db
    // 1. Unusable quality: 8% ~= -96db
    // 0. No signal

void test_checkZeroBarWhenNoSignal(void) {
  const int expected = 0;
  long signalStrength = -100;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkOneBarWhenSignalRSSIUnstableQuality(void) {
  const int expected = 1;
  long signalStrength = -96;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkTwoBarsWhenSignalRSSILowQuality(void) {
  const int expected = 2;
  long signalStrength = -85;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkThreeBarsWhenSignalMediumQuality(void) {
  const int expected = 3;
  long signalStrength = -75;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkFourBarsWhenSignalGoodQuality(void) {
  const int expected = 4;
  long signalStrength = -65;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkFiveBarsWhenSignalHighQuality(void) {
  const int expected = 5;
  long signalStrength = -55;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkOneBarIfRSSINegative86(void)
{
  const int expected = 1;
  long signalStrength = -86;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkFourBarIfRSSINegative60(void)
{
  const int expected = 4;
  long signalStrength = -60;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

void test_checkZeroBarIfRSSINegative100(void)
{
  const int expected = 0;
  long signalStrength = -100;
  int result = getBarsSignal(signalStrength);

  TEST_ASSERT_EQUAL_INT(expected, result);
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_checkZeroBarWhenNoSignal);
  RUN_TEST(test_checkOneBarWhenSignalRSSIUnstableQuality);
  RUN_TEST(test_checkTwoBarsWhenSignalRSSILowQuality);
  RUN_TEST(test_checkThreeBarsWhenSignalMediumQuality);
  RUN_TEST(test_checkFourBarsWhenSignalGoodQuality);
  RUN_TEST(test_checkFiveBarsWhenSignalHighQuality);
  RUN_TEST(test_checkOneBarIfRSSINegative86);
  RUN_TEST(test_checkFourBarIfRSSINegative60);
  RUN_TEST(test_checkZeroBarIfRSSINegative100);
  return UNITY_END();
}

// WARNING!!! PLEASE REMOVE UNNECESSARY MAIN IMPLEMENTATIONS //

/**
  * For native dev-platform or for some embedded frameworks
  */
int main(void) {
  return runUnityTests();
}