//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_PAGE_H
#define DEFENDERHUB_PAGE_H

#include <Arduino.h>
#include <Adafruit_SSD1351.h>
#include <Car.h>


#define PAGE_TYPE_STATIC 0
#define PAGE_TYPE_GAUGE 1


class Page {
public:
    Page(Car& car) : page_type(PAGE_TYPE_STATIC), car(car) {};
    virtual String lcd_first_line() = 0;
    virtual String lcd_second_line() = 0;
    virtual void draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) { };

    int get_page_type();
    virtual void update_values() { return; }
    virtual int refreshrate_seconds() { return 10; }
    virtual bool needs_display_update() { return false; }
    virtual String get_page_name() { return "unnamed"; };

    virtual int get_gauge_value() { return 0; }


protected:
    int page_type;
    Car& car;
    void update_label(Adafruit_SSD1351 &oled, const char label[], const String value, int x, int y, int h, bool big_value=false, int color=0x07E0);
    void update_label(Adafruit_SSD1351 &oled, const char label[], double value, int x, int y, int h, bool big_value=false, int color=0x07E0);
    void update_label(Adafruit_SSD1351 &oled, const char label[], int value, int x, int y, int h, bool big_value=false, int color=0x07E0);

private:
    void update_label_basics(Adafruit_SSD1351 &oled, const char label[], int x, int y, int h, bool big_value=false, int color=0x07E0);
};

#endif //DEFENDERHUB_PAGE_H
