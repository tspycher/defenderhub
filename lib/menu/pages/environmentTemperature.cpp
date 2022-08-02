//
// Created by Thomas Spycher on 02.08.22.
//

#include "environmentTemperature.h"
#include "sensorEnvironmentTemperature.h"


EnvironmentTemperature::EnvironmentTemperature(int onewirebus) {
    sensor = new SensorEnvironmentTemperature(onewirebus);
}

String EnvironmentTemperature::lcd_first_line() {
    float temperature = sensor->get_temperature_outside();
    return "Outside: " + (String)temperature;
}

String EnvironmentTemperature::lcd_second_line() {
    float temperature = sensor->get_temperature_inside();
    return "Inside: " + (String)temperature;
}