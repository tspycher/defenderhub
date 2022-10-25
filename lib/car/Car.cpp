//
// Created by Thomas Spycher on 25.10.22.
//

#include "Car.h"
Car::Car(struct UnitConfig &unitconfig) : unitconfig(unitconfig) {

}
UnitConfig* Car::get_unitconfig() {
    return &unitconfig;
}

double Car::get_temperature_inside() {
    return 21.5;
}

double Car::get_temperature_outside() {
    return 4.3;
}