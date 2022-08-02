//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_DEFENDERMENU_H
#define DEFENDERHUB_DEFENDERMENU_H

#include "page.h"
#include <LiquidCrystal.h>


class DefenderMenu {
public:
    DefenderMenu(void);
    void update_lcd(void);
private:
    Page *pages[1];
    LiquidCrystal *lcd;
};

#endif //DEFENDERHUB_DEFENDERMENU_H
