//
// Created by Thomas Spycher on 18.08.22.
//

#include "ObdEngineRpm.h"

ObdEngineRpm::ObdEngineRpm(Parameter &obd_parameter) : Page(obd_parameter){
    page_type = PAGE_TYPE_GAUGE;
}

ObdEngineRpm::~ObdEngineRpm() {
}

int ObdEngineRpm::get_gauge_value() {
    return (int) (100.0 / 1000.0 * get_obd_value());
}

float ObdEngineRpm::get_obd_value() {
    //return (float) random(0, 1000);
    return (float) obd_parameter->get_current_value();
}

String ObdEngineRpm::lcd_first_line() {
    return "RPM";
}

String ObdEngineRpm::lcd_second_line() {
    return String();
}