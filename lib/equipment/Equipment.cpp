//
// Created by Thomas Spycher on 05.08.22.
//

#include "Equipment.h"
#include "Arduino.h"


Equipment::Equipment(Relay *relays) :relays(relays) {
    for (int r; r < num_relays(); ++r) {
        pinMode(relays[r].pin, OUTPUT);
    }
}

int Equipment::num_relays() {
    return (int) sizeof(*relays)/sizeof(relays[0]);
}

void Equipment::turn_off(int index) {
    Serial.print("Turning off: ");
    Serial.println(relays[index].name);
    digitalWrite(relays[index].pin, HIGH);
}

void Equipment::turn_on(int index) {
    Serial.print("Turning on: ");
    Serial.println(relays[index].name);
    digitalWrite(relays[index].pin, LOW);
}