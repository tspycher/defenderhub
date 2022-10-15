//
// Created by Thomas Spycher on 02.08.22.
//

#include "environmentTemperature.h"


EnvironmentTemperature::EnvironmentTemperature(int onewirebus) {
    sensor = new SensorEnvironmentTemperature(onewirebus);
    update_values();
}

bool EnvironmentTemperature::needs_lcd_update() {
    if (previous_tmp_outside != tmp_outside or previous_tmp_inside != tmp_inside) {
        return true;
    }
    return false;
}

int EnvironmentTemperature::refreshrate_seconds() {
    return 10;
}


void EnvironmentTemperature::update_values() {
    previous_tmp_inside = tmp_inside;
    previous_tmp_outside = tmp_outside;
    tmp_inside = sensor->get_temperature_inside();
    tmp_outside = sensor->get_temperature_outside();
}

String EnvironmentTemperature::lcd_first_line() {
    return "Outside:  " + (String)tmp_outside + (char)223;
}

String EnvironmentTemperature::lcd_second_line() {
    return "Inside:   " + (String)tmp_inside + (char)223;
}
