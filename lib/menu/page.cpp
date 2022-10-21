//
// Created by Thomas Spycher on 03.08.22.
//
#include "page.h"


int Page::get_page_type() {
    return page_type;
}

void Page::update_label(Adafruit_SSD1351 oled, const char label[], const char value[], int x, int y, int h, int color) {
    oled.setTextColor(color);

    oled.setTextSize(1);
    oled.setCursor(0,y);
    oled.print(label);

    oled.setCursor(x,y+(h/2));
    oled.fillRect(x, y+(h/2), 128-x, h, 0x0000);
    oled.setTextSize(2);
    oled.print(value);
}