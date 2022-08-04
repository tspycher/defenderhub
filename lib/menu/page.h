//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_PAGE_H
#define DEFENDERHUB_PAGE_H

#include <Arduino.h>

#define PAGE_TYPE_STATIC = 0;
#define PAGE_TYPE_GAUGE = 1;


class Page {
public:
    virtual ~Page() = default;

    virtual String lcd_first_line() = 0;
    virtual String lcd_second_line() = 0;
    int get_page_type();
    virtual int get_gauge_value() { return 0; };

protected:
    int page_type = 0;
};

#endif //DEFENDERHUB_PAGE_H
