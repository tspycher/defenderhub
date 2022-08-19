//
// Created by Thomas Spycher on 02.08.22.
//

#include "obdOil.h"

ObdOil::ObdOil(Parameter &obd_parameter) : Page(obd_parameter) {}

ObdOil::~ObdOil() {
}

int ObdOil::obd_oil_pressure() {
    return 45;
}

int ObdOil::obd_oil_temperature() {
    return obd_parameter->get_current_value();
}

String ObdOil::lcd_first_line() {
    return (String("Oil T: ") + obd_oil_temperature() + (char)223);
}

String ObdOil::lcd_second_line() {
    return (String("Oil P: ") + obd_oil_pressure() + String(" psi"));
}