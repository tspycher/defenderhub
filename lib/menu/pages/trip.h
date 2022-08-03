//
// Created by Thomas Spycher on 03.08.22.
//

#ifndef DEFENDERHUB_TRIP_H
#define DEFENDERHUB_TRIP_H

#include <Arduino.h>
#include "page.h"

class Trip : public Page {
public:
    ~Trip();

    String lcd_first_line() override;
    String lcd_second_line() override;
};
#endif //DEFENDERHUB_TRIP_H
