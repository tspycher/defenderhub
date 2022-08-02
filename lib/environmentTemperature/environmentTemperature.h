//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
#define DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
#include <DallasTemperature.h>
#include <OneWire.h>


class EnvironmentTemperature {
    const uint8_t INDEX_OUTSIDE = 0;
    const uint8_t INDEX_INSIDE = 1;
public:
    EnvironmentTemperature(int onewirebus);
    float get_temperature_outside();
    float get_temperature_inside();
protected:
    DallasTemperature *sensors;
    OneWire *oneWire;
    float get_temperature_for_index(uint8_t index);
};


#endif //DEFENDERHUB_ENVIRONMENTTEMPERATURE_H

