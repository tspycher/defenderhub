//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_SENSORENVIRONMENTTEMPERATURE_H
#define DEFENDERHUB_SENSORENVIRONMENTTEMPERATURE_H
#include <DallasTemperature.h>
#include <OneWire.h>


class SensorEnvironmentTemperature {

public:
    SensorEnvironmentTemperature(int onewirebus, uint8_t index_outside=0, uint8_t index_inside=1);
    float get_temperature_outside();
    float get_temperature_inside();
private:
    const uint8_t index_outside;
    const uint8_t index_inside;

    //const uint8_t INDEX_OUTSIDE = 0;
    //const uint8_t INDEX_INSIDE = 1;

    DallasTemperature *sensors;
    OneWire *oneWire;
    float get_temperature_for_index(uint8_t index);
};


#endif //DEFENDERHUB_SENSORENVIRONMENTTEMPERATURE_H

