//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_DEFENDERMENU_H
#define DEFENDERHUB_DEFENDERMENU_H

#include "page.h"
#include <LiquidCrystal.h>

#define PAGES 2

class DefenderMenu {
public:
    DefenderMenu(int rs=11, int enable=12, int d0=8, int d1=7, int d2=6, int d3=5);
    void welcome_screen(int delay_seconds=2);
    void update_lcd(void);
    void switch_page();
private:
    int current_page = 0;
    LiquidCrystal *lcd;
    Page *pages[PAGES];
    int total_pages();

};

#endif //DEFENDERHUB_DEFENDERMENU_H
