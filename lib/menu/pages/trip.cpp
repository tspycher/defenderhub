//
// Created by Thomas Spycher on 03.08.22.
//

#include "trip.h"

Trip::~Trip() {
}

String Trip::lcd_first_line() {
    return "Distance: 99km";
}

String Trip::lcd_second_line() {
    return "Time: 12m";
}