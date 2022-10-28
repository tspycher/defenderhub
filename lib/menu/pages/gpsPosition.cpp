//
// Created by Thomas Spycher on 02.08.22.
//

#include "gpsPosition.h"

String GpsPosition::get_page_name() {
    return "GPS Position";
}

String GpsPosition::lcd_first_line() {
    return String(22.22);
}

String GpsPosition::lcd_second_line() {
    return String(11.11);
}

bool GpsPosition::needs_display_update() {
    return car.is_gps_updated();
}

int GpsPosition::refreshrate_seconds() {
    return 10;
}

void GpsPosition::update_values() {
    Serial.println("*** Updating GPS Values");
}

void GpsPosition::draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) {
    update_label(oled, "Latitude", car.get_latitude(), 0, 20, 7);
    update_label(oled, "Longitude", car.get_longitude(), 128 / 2, 20, 7);

    update_label(oled, "Alt(m)", car.get_altitude(), 0,60,7);
    update_label(oled, "Speed", car.get_gpsspeed(), 0,85,7);
    update_label(oled, "Course", car.get_course(), 128/2,60,7);
    update_label(oled, "Satellites", car.get_satellites(), 128/2,85,7);
}