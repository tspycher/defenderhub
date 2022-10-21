//
// Created by Thomas Spycher on 03.08.22.
//

#ifndef DEFENDERHUB_GPSPOSITION_H
#define DEFENDERHUB_GPSPOSITION_H

#include <Page.h>

class GpsPosition : public Page {
public:
    String lcd_first_line() override;
    String lcd_second_line() override;
    void draw_on_oled_screen(Adafruit_SSD1351 oled, int oled_width, int oled_heigh) override;
    String get_page_name() override;

};
#endif //DEFENDERHUB_GPSPOSITION_H
