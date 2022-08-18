//
// Created by Thomas Spycher on 17.08.22.
//

#ifndef DEFENDERHUB_DEFENDEROBD2_H
#define DEFENDERHUB_DEFENDEROBD2_H

#include <Arduino.h>
#include <Parameter.h>


#define can_tx  12       // tx of serial can module, the yellow cable
#define can_rx  13
#define can_baud 9600 // 9600


class DefenderObd2 {
public:
    DefenderObd2();
    bool debug();
    int num_parameters();
    Parameter *get_parameter(int pid);
    Parameter *get_parameter(String name);
private:
    Parameter *parameters[3];
    MockSerial_CAN can;
};


#endif //DEFENDERHUB_DEFENDEROBD2_H
