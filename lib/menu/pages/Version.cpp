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
    return "Version/Debug";
}

void Version::draw_on_oled_screen(Adafruit_SSD1351 oled, int oled_width, int oled_heigh) {
    update_label(oled, "Version", VERSION, 0,20,14);
    update_label(oled, "Buildtime", BUILDTIME, 0,45,14);
    update_label(oled, "Copyright", "TSpycher", 0,90,14);
}