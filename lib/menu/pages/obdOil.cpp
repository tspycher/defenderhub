//
// Created by Thomas Spycher on 02.08.22.
//

#include "obdOil.h"

ObdOil::~ObdOil() {
}

String ObdOil::lcd_first_line() {
    return "Oil Temp.: ?" + (char)223;
}

String ObdOil::lcd_second_line() {
    return "Oil Pres.: ? psi";
}