//
// Created by Thomas Spycher on 26.10.22.
//

#ifndef DEFENDERHUB_TEMPERATURE_H
#define DEFENDERHUB_TEMPERATURE_H

#include <Page.h>

class Temperature : public Page {
public:
    Temperature(Car& car) : Page(car) {};

    String lcd_first_line() override;
    String lcd_second_line() override;
    void draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) override;
    String get_page_name() override;

    int refreshrate_seconds() override;
};



#endif //DEFENDERHUB_TEMPERATURE_H
