//
// Created by Thomas Spycher on 03.08.22.
//

#ifndef DEFENDERHUB_GPSPOSITION_H
#define DEFENDERHUB_GPSPOSITION_H

#include <Page.h>
#include <TinyGPSPlus.h>
#include <Car.h>


class GpsPosition : public Page {
public:
    GpsPosition(Car& car) : Page(car) {};
    String lcd_first_line() override;
    String lcd_second_line() override;
    void draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) override;
    String get_page_name() override;
    void update_values() override;
    int refreshrate_seconds() override;
    bool needs_display_update() override;

};
#endif //DEFENDERHUB_GPSPOSITION_H
