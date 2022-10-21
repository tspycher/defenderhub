//
// Created by Thomas Spycher on 02.08.22.
//

#include "gpsPosition.h"

String GpsPosition::get_page_name() {
    return "GPS Position";
}

String GpsPosition::lcd_first_line() {
    return "47.470833 N";
}

String GpsPosition::lcd_second_line() {
    return " 7.872920 E";
}

void GpsPosition::draw_on_oled_screen(Adafruit_SSD1351 oled, int oled_width, int oled_heigh) {
    update_label(oled, "Latitude", lcd_first_line().c_str(), 0,20,14);
    update_label(oled, "Longitude", lcd_second_line().c_str(), 0,50,14);
}