//
// Created by Thomas Spycher on 03.08.22.
//
#include "page.h"


int Page::get_page_type() {
    return page_type;
}

void Page::update_label(Adafruit_SSD1351 oled, const char label[], const char value[], int x, int y, int h, bool big_value, int color) {
    int line_space = 2;
    // reset old values
    oled.fillRect(x, y, 128-x, (2*h)+line_space, 0x0000);

    // set new values
    oled.setTextColor(color);
    oled.setTextSize(1);

    oled.setCursor(x,y);
    oled.print(label);

    oled.setCursor(x,y+h+line_space);
    if(big_value)
        oled.setTextSize(2);
    oled.print(value);
}