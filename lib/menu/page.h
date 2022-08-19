//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_PAGE_H
#define DEFENDERHUB_PAGE_H

#include <Arduino.h>
#include <Parameter.h>

#define PAGE_TYPE_STATIC 0
#define PAGE_TYPE_GAUGE 1


class Page {
public:
    Page();
    Page(Parameter &obd_parameter);
    virtual ~Page() = default;

    virtual String lcd_first_line() = 0;
    virtual String lcd_second_line() = 0;
    int get_page_type();
    void update_values();
    virtual int get_gauge_value() { return 0; };
protected:
    int page_type = 0;
    bool has_obd;
    Parameter *obd_parameter;
};

#endif //DEFENDERHUB_PAGE_H
