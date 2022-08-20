//
// Created by Thomas Spycher on 05.08.22.
//

#include "Equipment.h"
#include <Arduino.h>


Equipment::Equipment(Relay *relays) :relays(relays) {
    for (int r; r < num_relays(); ++r) {
        pinMode(relays[r].pin, OUTPUT);
        turn_off(r);
    }
}

int Equipment::num_relays() {
    return (int) sizeof(*relays)/sizeof(relays[0]);
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
    digitalWrite(relays[index].pin, HIGH);
}
void Equipment::turn_on(int index, void (*func)(char *, int)) {
    turn_on(index);
    func((char*)relays[index].name, 2000);
}
void Equipment::turn_on(int index) {
    Serial.print("Turning on: ");
    Serial.println(get_name(index));
    digitalWrite(relays[index].pin, LOW);
}