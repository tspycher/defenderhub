#include <Arduino.h>
#include "defendermenu.h"
#include <MemoryUsage.h>

#define LED_BUILTIN 13
#define PSEUDO_THREADS 2

const int UPDATE_TIMER = 3;
int alive_led_state;
int previous_free_ram = 0;
unsigned long looper = 0;
DefenderMenu *defender_menu;


void setup() {
    struct DisplayConfig displayconfig;
    displayconfig.rs = 11;
    displayconfig.enable = 12;
    displayconfig.d0 = 8;
    displayconfig.d1 = 7;
    displayconfig.d2 = 6;
    displayconfig.d3 = 5;

    defender_menu = new DefenderMenu(displayconfig);

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    alive_led_state = LOW;
    Serial.begin(9600);
    Serial.println("**** Defender Hub started ****");
    defender_menu->welcome_screen();
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
        defender_menu->switch_page();
        defender_menu->update_lcd();
    }
}

void loop_thread1() {
    if ((int) (millis()/10) % (int) (2*10) == 0) {
        if (defender_menu->type_of_current_page() == 1) {
            defender_menu->update_lcd_gauge();
        }
    }
}

void loop() {
    int thread = looper % PSEUDO_THREADS;

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



