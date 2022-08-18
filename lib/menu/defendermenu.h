//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_DEFENDERMENU_H
#define DEFENDERHUB_DEFENDERMENU_H

#include "page.h"
#include <Waveshare_LCD1602_RGB.h>
#include <DefenderObd2.h>

#define PAGES 6

struct UnitConfig {
    uint8_t lcd_red=0;
    uint8_t lcd_green=0;
    uint8_t lcd_blue=0;
    int lcd_cols = 16;
    int lcd_rows = 2;
    int one_wire_bus_pin = 3;
};

class DefenderMenu {
public:
    DefenderMenu(struct UnitConfig unitconfig);//int lcd_rs=11, int lcd_enable=12, int lcd_d0=8, int lcd_d1=7, int lcd_d2=6, int lcd_d3=5);
    void welcome_screen(int delay_seconds=2);
    void update_lcd(void);
    void update_lcd_gauge(void);
    void show_message(char *message, int delay_ms=2000);

    void switch_page();
    void special_option(); // long pressed button
    void extra_special_option(); // very long pressed button
    Page *get_current_page();
    int type_of_current_page();
private:
    int current_page = 0;
    UnitConfig unitconfig;
    void display_animated_text(String text, int row, int step_ms = 100);
    Waveshare_LCD1602_RGB *lcd;
    Page *pages[PAGES];
    int total_pages();
    bool is_defender_green;
    DefenderObd2 *obd;

};

#endif //DEFENDERHUB_DEFENDERMENU_H
