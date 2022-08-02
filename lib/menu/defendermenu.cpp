//
// Created by Thomas Spycher on 02.08.22.
//

#include "defendermenu.h"
#include "pages/environmentTemperature.h"
#include "pages/obdOil.h"
#include <LiquidCrystal.h>
#include <Arduino.h>


DefenderMenu::DefenderMenu(int rs, int enable, int d0, int d1, int d2, int d3) {
    pages[0] = new EnvironmentTemperature();
    pages[1] = new ObdOil();

    lcd = new LiquidCrystal(rs, enable, d0, d1, d2, d3);
    lcd->begin(16, 2);
}

void DefenderMenu::welcome_screen(int delay_seconds) {
    lcd->setCursor(0, 0);
    char const a[] = "  DEFENDER 110  ";
    for (int i = 0; i < (int) (sizeof(a)-1); i++) {
        lcd->setCursor(i, 0);
        lcd->print(a[i]);
        delay(100);
    }

    char const b[] = "one life,live it";
    for (int i = 0; i < (int) (sizeof(b)-1); i++) {
        lcd->setCursor(i, 1);
        lcd->print(b[i]);
        delay(100);
    }

    delay(delay_seconds*1000);
    lcd->clear();
}

void DefenderMenu::update_lcd(void) {
    Serial.println("Updating LCD");

    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(pages[current_page]->lcd_first_line().c_str());
    lcd->setCursor(0, 1);
    lcd->print(pages[current_page]->lcd_second_line().c_str());
}

int DefenderMenu::total_pages() {
    return sizeof(pages)/sizeof(pages[0]);
}

void DefenderMenu::switch_page() {
    if (current_page >= (total_pages() - 1)) {
        current_page = 0;
    } else {
        current_page++;
    }
}