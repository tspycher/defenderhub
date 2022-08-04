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
    return (int) (100.0 / 1000.0 * get_obd_value());
}

float Boost::get_obd_value() {
    return (float) random(0, 1000);
}

String Boost::lcd_first_line() {
    return "Boost";
}

String Boost::lcd_second_line() {
    return String();
}