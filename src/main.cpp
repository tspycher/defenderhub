/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include <time.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13

#endif

int update_timer = 5;

void setup() {
    Serial.begin(9600);
    Serial.println("started program");
}

void loop() {
    if((millis()/100) % (update_timer*10) == 0) {
        Serial.println("i am alive");
    }
}


