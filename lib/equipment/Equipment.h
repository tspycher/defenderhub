//
// Created by Thomas Spycher on 05.08.22.
//

#ifndef DEFENDERHUB_EQUIPMENT_H
#define DEFENDERHUB_EQUIPMENT_H

#define ADDRESS_PCF8574_0 0x20
#define ADDRESS_PCF8574_1 0x21

#include <pcf8574.h>


struct Relay {
    int relay_pin;
    int switch_pin;
    char *name;
};

class Equipment {
public:
    Equipment(Relay *relays, int num_relays);

    void turn_off(int index, void (*func)(char*, int));
    void turn_on(int index, void (*func)(char*, int));
    void turn_off(int index);
    void turn_on(int index);
    char *get_name(int index);
    int get_num_relays();
    void check_button_states();
private:
    Relay *relays;
    int num_relays;
    PCF8574 *extend_relais;
    PCF8574 *extend_switches;
};


#endif //DEFENDERHUB_EQUIPMENT_H
