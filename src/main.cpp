#include <Arduino.h>
#include <defendermenu.h>
#include <Equipment.h>
#include <MemoryUsage.h>

#include <Wire.h>
#define LED_BUILTIN 13
#define PSEUDO_THREADS 2
#define BUTTON 3 // with interrupt
#define PIEZO_PIN 5
#define ONEWIRE_PIN 4

#define SERIAL_BAUD 115200 // 9600

#define BUTTON_SHORT_PRESS 1000
#define BUTTON_LONG_PRESS 3000
#define BUTTON_VERY_LONG_PRESS 5000

const unsigned long UPDATE_TIMER = 10 * 1000;
const unsigned long UPDATE2_TIMER = 0.1 * 1000;


int alive_led_state;
int previous_free_ram = 0;
unsigned long looper = 0;
long int last_button_signal = 0;
long int last_button_press = 0;


DefenderMenu *defender_menu;
Equipment *equipment;




void button_pressed() {
    Serial.println("BUTTON PRESSED");
    defender_menu->switch_page_by_interrupt();
    Serial.println(defender_menu->get_current_page());
}

void button_debouncer() {
    int diff = millis() - last_button_signal;
    int diff2 = millis() - last_button_press;

    last_button_signal = millis();

    if (diff >= 50 and diff <= BUTTON_SHORT_PRESS) {
        if (diff2 >= BUTTON_SHORT_PRESS/4) {
            button_pressed();
            last_button_press = millis();
        }
    }
}

void setup() {
    // CONFIGURING RELAYS
    /*struct Relay relay0 = {0,0, (char*)"Radio"};
    struct Relay relay1 = {1,1, (char*)"Light1"};
    struct Relay relay2 = {2,2, (char*)"Light2"};
    struct Relay relay3 = {3,3, (char*)"Light3"};
    struct Relay relay4 = {4,4, (char*)"Light Inside"};
    struct Relay relay5 = {5,5, (char*)"Other"};
    struct Relay relay6 = {6,6, (char*)"This"};
    struct Relay relay7 = {7,7, (char*)"That"};
     */

    //Relay relays[] = {relay0,relay1, relay2, relay3, relay4, relay5, relay6, relay7};
    //equipment = new Equipment(relays, sizeof relays / sizeof relays[0]);

    // CONFIGURE THE DISPLAY
    struct UnitConfig config;
    config.lcd_green = 100;
    config.piezo_pin = PIEZO_PIN;
    config.one_wire_bus_pin = ONEWIRE_PIN;
    config.with_sound = false;

    // CONFIGURE PINS
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON), button_debouncer, RISING);
    digitalWrite(LED_BUILTIN, LOW);
    alive_led_state = LOW;

    // START SERIAL
    Serial.begin(SERIAL_BAUD);

    // INITIALIZING APPLICATION
    Serial.println("**** Defender Hub started ****");
    defender_menu = new DefenderMenu(config);
    defender_menu->welcome_screen(1);
    defender_menu->switch_page(0);
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

// Helper Function to switch equipment and display message
void switch_equipment(bool on, int index) {
    char message[16];

    if (on) {
        (String(equipment->get_name(index)) + String(" ON")).toCharArray(message, 16);
        equipment->turn_on(index);
        defender_menu->show_message(message);
    } else {
        (String(equipment->get_name(index)) + String(" OFF")).toCharArray(message, 16);
        equipment->turn_off(index);
        defender_menu->show_message(message);
    }
}

// Pseudo Thread 0 Loop, Slow Update
void loop_thread0() { // Slow Thread
    if (millis() % UPDATE_TIMER == 0) {
        //memory_state();
        toggle_alive_led();
        defender_menu->update_lcd();
    }
}

// Pseudo Thread 1 Loop, Fast Update
void loop_thread1() { // Fast Thread
    defender_menu->perform_interrupt_switch_page();

    if (millis() % UPDATE2_TIMER == 0) {
        if (defender_menu->type_of_current_page() == PAGE_TYPE_GAUGE) {
            defender_menu->update_current_page_data();
            defender_menu->update_lcd_gauge();
        }
    }
}


void loop() {
    int thread = looper % PSEUDO_THREADS;

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

    //equipment->check_button_states();

    ++looper;
}