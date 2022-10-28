//
// Created by Thomas Spycher on 14.10.22.
//

#include "Version.h"
#include "versiondetails.h"
#include "defendermenu.h"

int Version::refreshrate_seconds() {
    return 3;
}

String Version::lcd_first_line() {
    return String(BUILDTIME);
}

String Version::lcd_second_line() {
    return String(VERSION);
}

String Version::get_page_name() {
    return "Version";
}

void Version::draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) {
    update_label(oled, "Version", VERSION, 0,20,7, false);
    update_label(oled, "Buildtime", BUILDTIME, 0,45,7, false);
    update_label(oled, "Copyright", "TSpycher", 0,70,7, false);
}