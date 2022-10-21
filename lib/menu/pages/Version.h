//
// Created by Thomas Spycher on 14.10.22.
//

#ifndef DEFENDERHUB_VERSION_H
#define DEFENDERHUB_VERSION_H

#include <Page.h>

class Version : public Page {
public:
    String lcd_first_line() override;
    String lcd_second_line() override;
    void draw_on_oled_screen(Adafruit_SSD1351 oled, int oled_width, int oled_heigh) override;
    String get_page_name() override;

    int refreshrate_seconds() override;
};


#endif //DEFENDERHUB_VERSION_H
