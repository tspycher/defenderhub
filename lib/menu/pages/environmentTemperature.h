//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
#define DEFENDERHUB_ENVIRONMENTTEMPERATURE_H

#include <Arduino.h>
#include "page.h"

class EnvironmentTemperature : public Page {
public:
    String lcd_first_line();
    String lcd_second_line();
};

#endif //DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
