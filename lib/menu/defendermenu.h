//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_DEFENDERMENU_H
#define DEFENDERHUB_DEFENDERMENU_H

#include "page.h"
#include "Waveshare_LCD1602_RGB.h"

#define PAGES 6

struct DisplayConfig {
    uint8_t red=0;
    uint8_t green=0;
    uint8_t blue=0;
    int cols = 16;
    int rows = 2;
};

class DefenderMenu {
public:
    DefenderMenu(struct DisplayConfig displayconfig);//int lcd_rs=11, int lcd_enable=12, int lcd_d0=8, int lcd_d1=7, int lcd_d2=6, int lcd_d3=5);
    void welcome_screen(int delay_seconds=2);
    void update_lcd(void);
    void update_lcd_gauge(void);

    void switch_page();
    int type_of_current_page();
private:
    int current_page = 0;
    DisplayConfig displayconfig;
    void display_animated_text(String text, int row, int step_ms = 100);
    Waveshare_LCD1602_RGB *lcd;
    Page *pages[PAGES];
    int total_pages();

};

#endif //DEFENDERHUB_DEFENDERMENU_H
