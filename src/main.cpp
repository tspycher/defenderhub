
#include <Arduino.h>

#include "environmentTemperature.h"
#include "defendermenu.h"
#include <time.h>


#ifndef LED_BUILTIN
#define LED_BUILTIN 13

#endif
#define ONE_WIRE_BUS 2

const int UPDATE_TIMER = 5;
int alive_led_state;
DefenderMenu lcd_menu;

//LiquidCrystal lcd(11, 12, 8, 7, 6, 5);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    alive_led_state = LOW;
    Serial.begin(9600);
    Serial.println("started program");
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
    //if((millis()/100) % (UPDATE_TIMER*10) == 0) {
        toggle_alive_led();
        lcd_menu.update_lcd();
    //}
    delay(UPDATE_TIMER*1000);
}


