//
// Created by Thomas Spycher on 03.08.22.
//

#include "consumption.h"

Consumption::~Consumption() {
}

String Consumption::lcd_first_line() {
    return "Trip: 12.2";
}

String Consumption::lcd_second_line() {
    return "Current: 15.6";
}