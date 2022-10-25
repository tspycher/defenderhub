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
    GpsPosition(Car &car) : car(car),
        lat(0.0),
        lng(0.0),
        alt(0.0),
        course(0.0),
        speed(0.0),
        satellites(0),
        previous_lat(0.0),
        previous_lng(0.0),
        previous_alt(0.0),
        previous_course(0.0),
        previous_speed(0.0),
        previous_satellites(0) {};
    String lcd_first_line() override;
    String lcd_second_line() override;
    void draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) override;
    String get_page_name() override;
    void update_values() override;
    int refreshrate_seconds() override;
    bool needs_lcd_update() override;
private:
    Car &car;
    double lat;
    double lng;
    double alt;
    double course;
    double speed;
    uint32_t satellites;

    double previous_lat;
    double previous_lng;
    double previous_alt;
    double previous_course;
    double previous_speed;
    uint32_t previous_satellites;

};
#endif //DEFENDERHUB_GPSPOSITION_H
