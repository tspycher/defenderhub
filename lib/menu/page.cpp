//
// Created by Thomas Spycher on 03.08.22.
//
#include "page.h"

Page::Page() : page_type(PAGE_TYPE_STATIC) {
    has_obd = false;
}

Page::Page(Parameter &obd_parameter) : page_type(PAGE_TYPE_STATIC), obd_parameter(&obd_parameter) {
    has_obd = true;
}

int Page::get_page_type() {
    return page_type;
}

void Page::update_values() {
    if (has_obd) {
        obd_parameter->request_from_obd();
    }
}