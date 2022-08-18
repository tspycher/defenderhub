//
// Created by Thomas Spycher on 17.08.22.
//

#include "DefenderObd2.h"
#include "parameters/OilTemperature.h"
#include "parameters/EngineSpeed.h"
#include "parameters/AbsoluteBarometricPressure.h"

DefenderObd2::DefenderObd2() {
    can.begin(can_tx, can_rx, can_baud);

    parameters[0] = new EngineSpeed(can);
    parameters[1] = new AbsoluteBarometricPressure(can);
    parameters[2] = new OilTemperature(can);


    /*if(can.baudRate(SERIAL_RATE_115200)) {
        Serial.println("Set Baudrate to 115200");
        delay(1000);
    } else {
        Serial.println("Could not set Baudrate to 115200");
        delay(1000);
    }

    if(can.canRate(CAN_RATE_500)) {
        Serial.println("Set CAN Rate to 500");
        delay(1000);
    } else {
        Serial.println("Could not set CAN RAte to 500");
        delay(1000);
    }*/
}

int DefenderObd2::num_parameters() {
    return (int) sizeof(parameters)/sizeof(parameters[0]);
}

Parameter *DefenderObd2::get_parameter(String name) {
    for (int i=0; i<num_parameters(); ++i) {
        if (parameters[i]->get_name() == name)
            return parameters[i];
    }
    return NULL;
}

Parameter *DefenderObd2::get_parameter(int pid) {
    for (int i=0; i<num_parameters(); ++i) {
        if (parameters[i]->get_pid() == pid)
            return parameters[i];
    }
    return NULL;
}

bool DefenderObd2::debug() {
    unsigned long id = 0;
    unsigned char dta[8];

    if(can.recv(&id, dta))
    {
        if (id < 2)
            return false;

        Serial.print("id: 0x");
        Serial.print((int)id, HEX);
        Serial.print(", ");
        Serial.print("id2: 0x");
        Serial.print((int)dta[2], HEX);
        Serial.print(", ");

        for(int i=0; i<8; i++)
        {
            Serial.print(i);
            Serial.print(":0x");
            Serial.print((int)dta[i],HEX);
            Serial.print(", ");
        }
        Serial.println("DONE");
        Parameter *p = get_parameter(dta[2]); // id
        if (p) {
            Serial.print("\tFOUND PARAMETER! ID: ");
            Serial.print(dta[2]);
            Serial.print(" ");
            Serial.print(p->get_name());
            Serial.print(" with Value: ");
            Serial.println(p->get_current_value());

            p->load_block(dta);
            Serial.println();
            delay(500);
        }
        return true;
    }
    Serial.println("no data received");
    return false;
}
