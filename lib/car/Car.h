//
// Created by Thomas Spycher on 25.10.22.
//

#ifndef DEFENDERHUB_CAR_H
#define DEFENDERHUB_CAR_H

#include <Adafruit_GFX.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

struct UnitConfig {
    uint8_t lcd_red=0;
    uint8_t lcd_green=0;
    uint8_t lcd_blue=0;
    int lcd_cols = 16;
    int lcd_rows = 2;
    int one_wire_bus_pin;
    int piezo_pin;
    bool with_sound;

    int oled_sclk_pin;
    int oled_mosi_pin;
    int oled_dc_pin;
    int oled_cs_pin;
    int oled_rst_pin;
    int oled_screen_width = 128;
    int oled_screen_height = 128;

    int gps_rx;
    int gps_tx;
    int gps_baud = 9600;
};


class Car {
public:
    Car(struct UnitConfig &unitconfig);//int lcd_rs=11, int lcd_enable=12, int lcd_d0=8, int lcd_d1=7, int lcd_d2=6, int lcd_d3=5);
    double get_temperature_inside();
    double get_temperature_outside();
    UnitConfig *get_unitconfig();
    bool is_gps_ready();
    TinyGPSPlus *get_gps();
    void update_gps(bool debug=false);
    double get_latitude();
    double get_longitude();
    double get_gpsspeed();
    double get_altitude();
    double get_course();
    int get_satellites();
private:
    UnitConfig &unitconfig;
    SoftwareSerial *gps_serial;
    TinyGPSPlus *gps;
    bool gps_ready;

};


#endif //DEFENDERHUB_CAR_H
