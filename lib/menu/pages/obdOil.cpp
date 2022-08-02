//
// Created by Thomas Spycher on 02.08.22.
//

#include "obdOil.h"

String ObdOil::lcd_first_line() {
    return "Oil Temp.: ? C";
}

String ObdOil::lcd_second_line() {
    return "Oil Pres.: ? psi";
}