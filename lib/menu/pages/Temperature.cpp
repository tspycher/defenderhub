//
// Created by Thomas Spycher on 26.10.22.
//

#include "Temperature.h"
int Temperature::refreshrate_seconds() {
    return 3;
}

String Temperature::lcd_first_line() {
    return "";
}

String Temperature::lcd_second_line() {
    return "";
}

String Temperature::get_page_name() {
    return "Temperature";
}

void Temperature::draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) {
    update_label(oled, "in", car.get_temperature_inside(), 0,30,14, true);
    update_label(oled, "out", car.get_temperature_inside(), 0,70,14, true);
}