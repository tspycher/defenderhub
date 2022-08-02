//
// Created by Thomas Spycher on 01.08.22.
//
#include <unity.h>
#include <Arduino.h>

void setUp(void) {
    // set stuff up here
    //Serial.begin(9600);
}

void tearDown(void) {
    // clean stuff up here
}

void test_dingdong() {
    int x = 10;
    int y = x / 2;
    TEST_ASSERT_GREATER_OR_EQUAL(5, y);
}

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_dingdong);
    UNITY_END();
}

