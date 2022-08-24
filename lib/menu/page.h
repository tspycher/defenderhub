//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_PAGE_H
#define DEFENDERHUB_PAGE_H

#define PAGE_TYPE_STATIC 0
#define PAGE_TYPE_GAUGE 1

#include <Parameter.h>

class Page {
public:
    Page() : page_type(PAGE_TYPE_STATIC), has_obd(false) {};
    Page(int) : page_type(PAGE_TYPE_STATIC), has_obd(false) {};
    Page(Parameter &obd_parameter): page_type(PAGE_TYPE_STATIC), has_obd(true), obd_parameter(&obd_parameter) {};

    virtual String lcd_first_line() = 0;
    virtual String lcd_second_line() = 0;
    int get_page_type();
    void update_values();
    virtual int get_gauge_value() { return 0; }
protected:
    int page_type = 0;
    bool has_obd;
    Parameter *obd_parameter;
};

#endif //DEFENDERHUB_PAGE_H
