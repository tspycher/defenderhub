//
// Created by Thomas Spycher on 03.08.22.
//

#ifndef DEFENDERHUB_BOOST_H
#define DEFENDERHUB_BOOST_H
#include <Arduino.h>
#include "page.h"

class Boost : public Page {
public:
    Boost();
    ~Boost();
    String lcd_first_line() override;
    String lcd_second_line() override;
    int get_gauge_value() override;
protected:
    float get_obd_value();

};
#endif //DEFENDERHUB_BOOST_H
