
#include <Arduino.h>
#include <LiquidCrystal.h>

#include "environmentTemperature.h"
#include <time.h>


#ifndef LED_BUILTIN
#define LED_BUILTIN 13

#endif
#define ONE_WIRE_BUS 2

const int UPDATE_TIMER = 5;
int alive_led_state;

LiquidCrystal lcd(11, 12, 8, 7, 6, 5);
EnvironmentTemperature envt(ONE_WIRE_BUS);

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    alive_led_state = LOW;
    Serial.begin(9600);
    Serial.println("started program");

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Welcome");
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
    if((millis()/100) % (UPDATE_TIMER*10) != 0) {
        // only perform operations every x seconds
        return;
    }
    toggle_alive_led();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp1: ");
    lcd.print((double) envt.get_temperature_inside());
    lcd.setCursor(0, 1);
    lcd.print("Temp2: ");
    lcd.print((double)  envt.get_temperature_outside());

}


