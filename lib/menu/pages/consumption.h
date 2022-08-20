//
// Created by Thomas Spycher on 03.08.22.
//

#ifndef DEFENDERHUB_CONSUMPTION_H
#define DEFENDERHUB_CONSUMPTION_H

#include <Page.h>

class Consumption : public Page {
public:
    ~Consumption();

    String lcd_first_line() override;
    String lcd_second_line() override;
};
#endif //DEFENDERHUB_CONSUMPTION_H
