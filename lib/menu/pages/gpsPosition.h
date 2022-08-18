//
// Created by Thomas Spycher on 03.08.22.
//

#ifndef DEFENDERHUB_GPSPOSITION_H
#define DEFENDERHUB_GPSPOSITION_H

#include <Arduino.h>
#include <Page.h>

class GpsPosition : public Page {
public:
    ~GpsPosition();

    String lcd_first_line() override;
    String lcd_second_line() override;
};
#endif //DEFENDERHUB_GPSPOSITION_H
