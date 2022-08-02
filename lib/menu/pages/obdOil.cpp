//
// Created by Thomas Spycher on 02.08.22.
//

#include "obdOil.h"

String ObdOil::lcd_first_line() {
    return "Oil Temp: 100°";
}

String ObdOil::lcd_second_line() {
    return "Oil Pressure: 200hpa";
}