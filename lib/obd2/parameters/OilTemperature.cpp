//
// Created by Thomas Spycher on 17.08.22.
//

#include "OilTemperature.h"

OilTemperature::OilTemperature(OBDFacade &can) : Parameter(can)  {
    pid = 0x5C;
    name = "Engine oil temperature";
    unit = "C";
    maximum_value = 210;
    minimum_value = -40;
    data_bytes = 1;
    previous_value = minimum_value;
}

int OilTemperature::get_value() {
    return get_a() - 40;
}