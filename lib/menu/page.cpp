//
// Created by Thomas Spycher on 03.08.22.
//
#include "page.h"


int Page::get_page_type() {
    return page_type;
}

void Page::update_values() {
    if (has_obd) {
        obd_parameter->request_from_obd();
    }
}