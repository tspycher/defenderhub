//
// Created by Thomas Spycher on 15.10.22.
//

#ifndef DEFENDERHUB_COMPASS_H
#define DEFENDERHUB_COMPASS_H

#include <Page.h>

class Compass : public Page {
public:
    Compass();
    String lcd_first_line() override;
    String lcd_second_line() override;
    void update_values() override;

private:
    //int values[360];
    char *needle[360];
    int course;
};



#endif //DEFENDERHUB_COMPASS_H
