//
// Created by Thomas Spycher on 18.08.22.
//

#include "ObdEngineRpm.h"

ObdEngineRpm::ObdEngineRpm(Parameter &obd_parameter) : Page(obd_parameter){
    page_type = PAGE_TYPE_GAUGE;
}

int ObdEngineRpm::get_gauge_value() {
    return (int) (100.0 / obd_parameter->get_maximum_value() * get_obd_value());
}

float ObdEngineRpm::get_obd_value() {
    //return millis()/1 % obd_parameter->get_maximum_value();
    return (float) obd_parameter->get_current_value();
}

String ObdEngineRpm::lcd_first_line() {
    return String("RPM " + String((int)get_obd_value()));
}

String ObdEngineRpm::lcd_second_line() {
    return String();
}