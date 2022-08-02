#include <Arduino.h>
#include "defendermenu.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13

#endif

const int UPDATE_TIMER = 5;
int alive_led_state;
DefenderMenu defender_menu;


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    alive_led_state = LOW;
    Serial.begin(9600);
    Serial.println("started program");
    defender_menu.welcome_screen();
}

void toggle_alive_led() {
    if (alive_led_state == LOW) {
        digitalWrite(LED_BUILTIN, HIGH);
        alive_led_state = HIGH;
    } else {
        digitalWrite(LED_BUILTIN, LOW);
        alive_led_state = LOW;
    }
}

void loop() {
    toggle_alive_led();
    defender_menu.update_lcd();
    defender_menu.switch_page();
    delay(UPDATE_TIMER*1000);
}


