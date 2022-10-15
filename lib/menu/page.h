//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_PAGE_H
#define DEFENDERHUB_PAGE_H

#include <Arduino.h>

#define PAGE_TYPE_STATIC 0
#define PAGE_TYPE_GAUGE 1


class Page {
public:
    Page() : page_type(PAGE_TYPE_STATIC) {};
    Page(int) : page_type(PAGE_TYPE_STATIC) {};

    virtual String lcd_first_line() = 0;
    virtual String lcd_second_line() = 0;
    int get_page_type();
    virtual void update_values() { return; }
    virtual int refreshrate_seconds() { return 10; }
    virtual bool needs_lcd_update() { return false; }

    virtual int get_gauge_value() { return 0; }


protected:
    int page_type = 0;
};

#endif //DEFENDERHUB_PAGE_H
