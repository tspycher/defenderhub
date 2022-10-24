//
// Created by Thomas Spycher on 02.08.22.
//

#include "environmentTemperature.h"


EnvironmentTemperature::EnvironmentTemperature(int onewirebus): tmp_inside(21.5), tmp_outside(4.3), previous_tmp_inside(0.0), previous_tmp_outside(0.0) {
    //sensor = new SensorEnvironmentTemperature(onewirebus);
    //update_values();
}

String EnvironmentTemperature::get_page_name() {
    return "Temperature";
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
    /*previous_tmp_inside = tmp_inside;
    previous_tmp_outside = tmp_outside;
    tmp_inside = sensor->get_temperature_inside();
    tmp_outside = sensor->get_temperature_outside();
     */
}

String EnvironmentTemperature::lcd_first_line() {
    return "Outside:  " + (String)tmp_outside + (char)223;
}

String EnvironmentTemperature::lcd_second_line() {
    return "Inside:   " + (String)tmp_inside + (char)223;
}

void EnvironmentTemperature::draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) {
    update_label(oled, "Out", tmp_outside, 0, 30, 7, true);
    update_label(oled, "In", tmp_inside, 0, 70, 7, true);
}