//
// Created by Thomas Spycher on 05.08.22.
//

#include "Equipment.h"


Equipment::Equipment(Relay *relays, int num_relays) :relays(relays), num_relays(num_relays) {
    Serial.println("**** INIT EQUIPMENT ***");
    Serial.println(num_relays);

    extend_relais = new PCF8574(ADDRESS_PCF8574_0);
    extend_switches = new PCF8574(ADDRESS_PCF8574_1);

    // SEARCH FOR PCF8574
    for(int i = 0;i < 8;i++) {
        int address = PCF8574::combinationToAddress(i, false);
        if(PCF8574(address).read() != -1) {
            Serial.print("Found PCF8574: addr = 0x");
            Serial.println(address, HEX);
        }
    }

    for (int r; r < num_relays; ++r) {
        pinMode(*extend_relais, relays[r].relay_pin, OUTPUT);
        pinMode(*extend_switches, relays[r].switch_pin, INPUT_PULLUP);
        Serial.print("** initalize Equipment: ");
        Serial.println(relays[r].name);
        //turn_off(r);
    }
}

void Equipment::check_button_states() {
    int state;
    Serial.println(num_relays);
    for (int r=0; r < num_relays; ++r) {
        state = digitalRead(*extend_switches, relays[r].switch_pin);
        Serial.print("Reading Switch ");
        Serial.print(relays[r].switch_pin);
        Serial.print(" with state ");
        Serial.println(state);

        //if (state == LOW) {
        //    digitalToggle(*extend_switches, relays[r].switch_pin);
        //    delay(200);
        //}
    }
}

int Equipment::get_num_relays() {
    return num_relays;
}

char* Equipment::get_name(int index) {
    return relays[index].name;
}

void Equipment::turn_off(int index, void (*func)(char *, int)) {
    turn_off(index);
    func((char*)relays[index].name, 2000);
}
void Equipment::turn_off(int index) {
    Serial.print("Turning off: ");
    Serial.println(get_name(index));
    digitalWrite(*extend_relais, relays[index].relay_pin, HIGH);
}
void Equipment::turn_on(int index, void (*func)(char *, int)) {
    turn_on(index);
    func((char*)relays[index].name, 2000);
}
void Equipment::turn_on(int index) {
    Serial.print("Turning on: ");
    Serial.println(get_name(index));
    digitalWrite(*extend_relais, relays[index].relay_pin, LOW);
}