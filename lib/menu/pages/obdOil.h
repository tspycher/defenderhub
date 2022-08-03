//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_OBDOILTEMPERATURE_H
#define DEFENDERHUB_OBDOILTEMPERATURE_H

#include <Arduino.h>
#include "page.h"

class ObdOil : public Page {
    ~ObdOil();
public:
    String lcd_first_line();
    String lcd_second_line();
};

#endif //DEFENDERHUB_OBDOILTEMPERATURE_H
