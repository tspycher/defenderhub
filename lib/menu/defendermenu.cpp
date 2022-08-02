//
// Created by Thomas Spycher on 02.08.22.
//

#include "defendermenu.h"
#include "pages/environmentTemperature.h"
#include <LiquidCrystal.h>
#include <Arduino.h>


DefenderMenu::DefenderMenu(void) {
    pages[0] = new EnvironmentTemperature();

    lcd = new LiquidCrystal(11, 12, 8, 7, 6, 5);
    lcd->begin(16, 2);
    lcd->setCursor(0, 0);
    lcd->print("Welcome");
}

void DefenderMenu::update_lcd(void) {
    Serial.println("Updating LCD");

    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print(pages[0]->lcd_first_line().c_str());
    lcd->setCursor(0, 1);
    lcd->print(pages[0]->lcd_second_line().c_str());
}