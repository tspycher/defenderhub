//
// Created by Thomas Spycher on 05.08.22.
//

#ifndef DEFENDERHUB_EQUIPMENT_H
#define DEFENDERHUB_EQUIPMENT_H

#include <Arduino.h>


struct Relay {
    int pin;
    char *name;
};

class Equipment {
public:
    Equipment(Relay *relays);

    void turn_off(int index);
    void turn_on(int index);

    int num_relays();
private:
    Relay *relays;
};


#endif //DEFENDERHUB_EQUIPMENT_H
