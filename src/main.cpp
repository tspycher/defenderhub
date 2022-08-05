#include <Arduino.h>
#include "defendermenu.h"
#include "Equipment.h"
#include <MemoryUsage.h>

#include <Wire.h>
#define LED_BUILTIN 13
#define PSEUDO_THREADS 2
#define BUTTON 2

const int UPDATE_TIMER = 10;
const int LONG_PRESS_DURATION_SECONDS = 2;
const int EXTRA_LONG_PRESS_DURATION_SECONDS = 4;

int switch_state = 0;
int alive_led_state;
int previous_free_ram = 0;
unsigned long looper = 0;
int button_long_press_timer = 0;
bool button_action_to_performe = false;

DefenderMenu *defender_menu;
Equipment *equipment;

void setup() {
    struct Relay relay1 = {4, (char*)"Radio"};

    struct UnitConfig config;
    config.lcd_green = 100;

    defender_menu = new DefenderMenu(config);

    Relay relays[] = {relay1};
    equipment = new Equipment(relays);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    alive_led_state = LOW;
    Serial.begin(9600);
    Serial.println("**** Defender Hub started ****");
    defender_menu->welcome_screen(1);
    Serial.println("**** Start Loop ****");
    defender_menu->update_lcd();
}


void memory_state() {
    int free_ram = mu_freeRam();
    if (free_ram > previous_free_ram and previous_free_ram > 0) {
        Serial.println("!!!!!!! Potential Memory leak, increased free ram since last loop");
    } else {
        FREERAM_PRINT;
    }
    previous_free_ram = mu_freeRam();
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

void loop_thread0() {
    if ((int) (millis()/10) % (int) (UPDATE_TIMER*100) == 0) {
        memory_state();
        toggle_alive_led();
        defender_menu->update_lcd();

        //equipment->turn_off(0);
        //delay(500);
        //equipment->turn_on(0);
    }
}

void loop_thread1() {
    if ((int) (millis()/10) % (int) (3*10) == 0) {
        if (defender_menu->type_of_current_page() == 1) {
            defender_menu->update_lcd_gauge();
        }
    }
}

void loop() {
    int thread = looper % PSEUDO_THREADS;

    // Handling the Switch
    switch_state = digitalRead(BUTTON);
    if (switch_state == HIGH and !button_action_to_performe) {
        button_long_press_timer = millis();
        button_action_to_performe = true;
    } else if (switch_state == LOW and button_action_to_performe) {
        int button_press_duration = millis() - button_long_press_timer;
        if (button_press_duration >= EXTRA_LONG_PRESS_DURATION_SECONDS*1000) {
            Serial.write("Button has been pressed very long");
            defender_menu->extra_special_option();
        } else if (button_press_duration >= LONG_PRESS_DURATION_SECONDS*1000) {
            Serial.write("Button has been pressed long");
            defender_menu->special_option();
        } else {
            Serial.write("Button has been pressed short");
            defender_menu->switch_page();
            defender_menu->update_lcd();
        }
        button_action_to_performe = false;
    }

    // Loop-Switching to simulate multi threading
    switch (thread) {
        case 0:
            loop_thread0();
            break;
        case 1:
            loop_thread1();
            break;
        default:
            Serial.println("No thread registered for id: "+thread);
            break;
    }
    ++looper;
}