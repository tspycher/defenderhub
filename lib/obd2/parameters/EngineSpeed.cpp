//
// Created by Thomas Spycher on 17.08.22.
//

#include "EngineSpeed.h"


EngineSpeed::EngineSpeed(OBDFacade &can): Parameter(can) {
    pid = 0x0C;
    name = "RPM";
    unit = "rpm";
    maximum_value = 6500; //16383;
    minimum_value = 0;
    data_bytes = 2;
    previous_value = 10;
}

int EngineSpeed::get_value() {
    if(is_initialized) {
        return (256*get_a()+get_b())/4;
    }
    return 0;
}