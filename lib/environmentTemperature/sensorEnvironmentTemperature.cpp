//
// Created by Thomas Spycher on 02.08.22.
//
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include "sensorEnvironmentTemperature.h"



SensorEnvironmentTemperature::SensorEnvironmentTemperature(int onewirebus){
    oneWire = new OneWire(onewirebus);
    sensors = new DallasTemperature(oneWire);
    sensors->begin();
}

float SensorEnvironmentTemperature::get_temperature_for_index(uint8_t index) {
    sensors->requestTemperatures();
    float temp = sensors->getTempCByIndex(index);
    Serial.print("Requested Temperature at Index ");
    Serial.print(index);
    Serial.print(" which reads ");
    Serial.print(temp);
    Serial.println("C");
    return temp;
}

float SensorEnvironmentTemperature::get_temperature_outside() {
    return get_temperature_for_index(INDEX_OUTSIDE);
}

float SensorEnvironmentTemperature::get_temperature_inside() {
    return get_temperature_for_index(INDEX_INSIDE);
}
