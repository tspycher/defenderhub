//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_PAGE_H
#define DEFENDERHUB_PAGE_H

#include <Arduino.h>

class Page {
public:
    virtual String lcd_first_line() = 0;
    virtual String lcd_second_line() = 0;
};

#endif //DEFENDERHUB_PAGE_H
