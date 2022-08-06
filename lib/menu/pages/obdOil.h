//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_OBDOILTEMPERATURE_H
#define DEFENDERHUB_OBDOILTEMPERATURE_H

#include <Arduino.h>
#include "page.h"

class ObdOil : public Page {
public:
    ~ObdOil();
    String lcd_first_line() override;
    String lcd_second_line() override;
private:
    int obd_oil_temperature();
    int obd_oil_pressure();
};

#endif //DEFENDERHUB_OBDOILTEMPERATURE_H
