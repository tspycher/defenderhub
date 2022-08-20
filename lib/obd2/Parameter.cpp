//
// Created by Thomas Spycher on 17.08.22.
//

#include "Parameter.h"

Parameter::Parameter(OBDFacade &can) : can(&can), pid(0x00), name("UNKNOWN"), unit("?"), previous_value(0), current_value(0) {}

int Parameter::get_current_value() {
    return current_value;
}

String Parameter::get_pretty_value() {
    return name + String(" IS: ") + get_current_value() + unit;
}

int Parameter::get_maximum_value() {
    return maximum_value;
}

int Parameter::get_minimum_value() {
    return minimum_value;
}

bool Parameter::request_from_obd(unsigned int timeout_ms) {

    unsigned long __timeout = millis();
    unsigned char tmp[8] = {0x02, 0x01, get_pid(), 0, 0, 0, 0, 0};
    can->send(CAN_ID_PID, 0, 0, 8, tmp);   // SEND TO ID:0X55

    while(millis()-__timeout < timeout_ms)      // 1s time out
    {
        unsigned long id  = 0;
        unsigned char buf[8];

        if (can->recv(&id, buf)) {
            if(buf[1] == 0x41) {
                load_block(buf);
                return true;
            }
        }
    }
    return false;
}

int Parameter::get_previous_value() {
    return Parameter::previous_value;
}

unsigned char Parameter::get_pid() {
    return pid;
}

String Parameter::get_name() {
    return name;
}

void Parameter::load_block(unsigned char raw_data[]) {
    Serial.print("\tLoading Block: ");
    previous_value = current_value;
    for (int i = 0; i < 8; ++i) {
        Serial.print(i);
        Serial.print(":0x");
        Serial.print((int)raw_data[i], HEX);
        Serial.print(" ");

        data[i] = &raw_data[i];
    }
    Serial.println("Done");
    current_value = get_value();
}

int Parameter::get_a() {
    return (int) *data[3];
}
int Parameter::get_b() {
    return (int) *data[4];
}
int Parameter::get_c() {
    return (int) *data[5];
}
int Parameter::get_d() {
    return (int) *data[6];
}