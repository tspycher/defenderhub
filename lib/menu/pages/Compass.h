//
// Created by Thomas Spycher on 15.10.22.
//

#ifndef DEFENDERHUB_COMPASS_H
#define DEFENDERHUB_COMPASS_H

#include <Page.h>


class Compass : public Page {
public:
    Compass(Car& car);
    String lcd_first_line() override;
    String lcd_second_line() override;
    void draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) override;

    void update_values() override;
    int refreshrate_seconds() override;
    bool needs_display_update() override;
private:
    char *needle[360];
    int course;
    int previous_course;

};



#endif //DEFENDERHUB_COMPASS_H
