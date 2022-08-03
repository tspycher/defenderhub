//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_DEFENDERMENU_H
#define DEFENDERHUB_DEFENDERMENU_H

#include "page.h"
#include <LiquidCrystal.h>

#define PAGES 2

struct DisplayConfig {
    int rs;
    int enable;
    int d0;
    int d1;
    int d2;
    int d3;
    int cols = 16;
    int rows = 2;
};

class DefenderMenu {
public:
    DefenderMenu(struct DisplayConfig displayconfig);//int lcd_rs=11, int lcd_enable=12, int lcd_d0=8, int lcd_d1=7, int lcd_d2=6, int lcd_d3=5);
    void welcome_screen(int delay_seconds=2);
    void update_lcd(void);
    void switch_page();
private:
    int current_page = 0;
    DisplayConfig displayconfig;
    void display_animated_text(String text, int row, int step_ms = 100);
    LiquidCrystal *lcd;
    Page *pages[PAGES];
    int total_pages();

};

#endif //DEFENDERHUB_DEFENDERMENU_H
