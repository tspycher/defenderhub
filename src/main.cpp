#include <Arduino.h>
#include <defendermenu.h>
#include <Equipment.h>
#include <MemoryUsage.h>

#include <Wire.h>
#define PSEUDO_THREADS 2
#define BUTTON 3 // with interrupt
#define PIEZO_PIN 5
#define ONEWIRE_PIN 4

#define OLED_SCLK_PIN 12
#define OLED_MOSI_PIN 11
#define OLED_DC_PIN   7
#define OLED_CS_PIN   10
#define OLED_RST_PIN  8

#define GPS_RX 9
#define GPS_TX 6
#define GPS_BAUD 9600

#define SERIAL_BAUD 115200 // 9600

#define BUTTON_SHORT_PRESS 1000
#define BUTTON_LONG_PRESS 3000
#define BUTTON_VERY_LONG_PRESS 5000

//const unsigned long UPDATE_TIMER = 10 * 1000;
const unsigned long UPDATE2_TIMER = 1 * 1000;
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
    // START SERIAL
    Serial.begin(SERIAL_BAUD);
    Serial.println("**** Serial Initialized ****");
    Serial.println("**** Starting Up ****");

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

    config.oled_cs_pin = OLED_CS_PIN;
    config.oled_dc_pin = OLED_DC_PIN;
    config.oled_mosi_pin = OLED_MOSI_PIN;
    config.oled_rst_pin = OLED_RST_PIN;
    config.oled_sclk_pin = OLED_SCLK_PIN;

    config.gps_baud = GPS_BAUD;
    config.gps_rx = GPS_RX;
    config.gps_tx = GPS_TX;

    Serial.println("**** Basic config done ****");


    // CONFIGURE PINS
    pinMode(BUTTON, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON), button_debouncer, RISING);
    Serial.println("**** Hardware Pin Configured ****");

    // INITIALIZING APPLICATION
    Serial.println("**** Menu Initializing started ****");
    defender_menu = new DefenderMenu(config);
    defender_menu->welcome_screen(1);
    defender_menu->switch_page(0);
    defender_menu->update_lcd();
    Serial.println("**** Menu Fully Loaded ****");

    Serial.println("**** Setup Completed ****");
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
    if (millis() % (defender_menu->get_page()->refreshrate_seconds() * 1000) == 0) {
        Serial.println("**** Thread 0 ****");
        defender_menu->get_page()->update_values();
        if (defender_menu->get_page()->needs_lcd_update()) {
            //memory_state();
            defender_menu->update_lcd();
        }
    }
}

// Pseudo Thread 1 Loop, Fast Update
void loop_thread1() { // Fast Thread
    defender_menu->perform_interrupt_switch_page();
    if (millis() % UPDATE2_TIMER == 0) {
        //Serial.println("**** Thread 1 ****");
        defender_menu->update_gps(false);

        if (defender_menu->type_of_current_page() == PAGE_TYPE_GAUGE) {
            //defender_menu->update_current_page_data();
            //defender_menu->update_lcd_gauge();
        }
    }
}


void loop() {
    int thread = looper % PSEUDO_THREADS;
    // Loop-Switching to simulate multi threading
    switch (thread) {
        case 0:
            //loop_thread0();
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