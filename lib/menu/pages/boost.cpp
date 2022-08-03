//
// Created by Thomas Spycher on 03.08.22.
//

#include "boost.h"

Boost::Boost() {
    page_type = 1;
}

Boost::~Boost() {
}

int Boost::get_gauge_value() {
    return random(0, 100); //(int) 100 / 1000 * get_obd_value();
}

float Boost::get_obd_value() {
    return (float) random(0, 1000);
}

String Boost::lcd_first_line() {
    return "Boost";
}

String Boost::lcd_second_line() {
    int lcd_gauge_value = (int) (16.0 / 100.0 * (float)get_gauge_value());
    String filler = "*";
    String gauge;

    for (int i = 0; i < lcd_gauge_value; i++)
        gauge += filler;

    return String(gauge);
}