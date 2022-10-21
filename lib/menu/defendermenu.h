//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_DEFENDERMENU_H
#define DEFENDERHUB_DEFENDERMENU_H

#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include "page.h"
#include "sound.h"

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

class DefenderMenu {
public:
    DefenderMenu(struct UnitConfig unitconfig);//int lcd_rs=11, int lcd_enable=12, int lcd_d0=8, int lcd_d1=7, int lcd_d2=6, int lcd_d3=5);
    void welcome_screen(int delay_seconds=2);
    void update_lcd(void);
    void update_lcd_gauge(void);
    void update_gps(bool debug);
    void show_message(char *message, int delay_ms=2000);

    void update_current_page_data();
    void switch_page_by_interrupt();
    void perform_interrupt_switch_page();
    void switch_page();
    void switch_page(int);
    int get_current_page();
    int type_of_current_page();
    Page *get_page();
private:
    int num_pages;
    int current_page = 0;
    UnitConfig unitconfig;
    bool oled_ready;
    bool lcd_ready;
    bool gps_ready;
    void display_animated_text(String text, int row, int step_ms = 100);

    void draw_base_menu();
    Adafruit_SSD1351 *oled;
    SoftwareSerial *gps_serial;
    TinyGPSPlus *gps;
    int total_pages();
    Sound *sound;
    Page *pages[4];
    bool interrupt_switch_page = false;
};

#endif //DEFENDERHUB_DEFENDERMENU_H
