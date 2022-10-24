//
// Created by Thomas Spycher on 02.08.22.
//

#include "gpsPosition.h"

String GpsPosition::get_page_name() {
    return "GPS Position";
}

String GpsPosition::lcd_first_line() {
    return String(lat);
}

String GpsPosition::lcd_second_line() {
    return String(lng);
}

bool GpsPosition::needs_lcd_update() {
    /*if(previous_lng != lng)
        return true;
    if(previous_lat != lat)
        return true;
    if(previous_alt != alt)
        return true;
    if(previous_speed != speed)
        return true;
    if(previous_course != course)
        return true;
    if(previous_satellites != satellites)
        return true;
    */
    return gps->location.isUpdated();
    //return false;
}

int GpsPosition::refreshrate_seconds() {
    return 10;
}


void GpsPosition::update_values() {
    Serial.println("*** Updating GPS Values");
}


void GpsPosition::draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) {
    update_label(oled, "Latitude", gps->location.lat(), 0, 20, 7);
    update_label(oled, "Longitude", gps->location.lng(), 128 / 2, 20, 7);

    update_label(oled, "Alt(m)", gps->altitude.meters(), 0,60,7);
    update_label(oled, "Speed", gps->speed.kmph(), 0,85,7);
    update_label(oled, "Course", gps->course.deg(), 128/2,60,7);
    update_label(oled, "Satellites", (const int)gps->satellites.value(), 128/2,85,7);

}