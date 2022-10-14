//
// Created by Thomas Spycher on 02.08.22.
//

#include "environmentTemperature.h"


EnvironmentTemperature::EnvironmentTemperature(int onewirebus) : age(0) {
    sensor = new SensorEnvironmentTemperature(onewirebus);
    update_values();
}

void EnvironmentTemperature::update_values() {
    if (millis() - age >= 10000) {
        tmp_inside = sensor->get_temperature_inside();
        tmp_outside = sensor->get_temperature_outside();
        age = millis();
    }
}

String EnvironmentTemperature::lcd_first_line() {
    return "Outside:  " + (String)tmp_outside + (char)223;
}

String EnvironmentTemperature::lcd_second_line() {
    return "Inside:   " + (String)tmp_inside + (char)223;
}
