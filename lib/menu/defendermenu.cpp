//
// Created by Thomas Spycher on 02.08.22.
//

#include "defendermenu.h"
#include "pages/environmentTemperature.h"
#include "pages/obdOil.h"
#include "pages/gpsPosition.h"
#include "pages/consumption.h"
#include "pages/boost.h"
#include "pages/trip.h"
#include <LiquidCrystal.h>
#include <Arduino.h>


DefenderMenu::DefenderMenu(struct DisplayConfig displayconfig) : displayconfig(displayconfig){
    pages[0] = new Boost();
    pages[1] = new EnvironmentTemperature();
    pages[2] = new ObdOil();
    pages[3] = new GpsPosition();
    pages[4] = new Consumption();
    pages[5] = new Trip();

    lcd = new LiquidCrystal(displayconfig.rs, displayconfig.enable, displayconfig.d0, displayconfig.d1, displayconfig.d2, displayconfig.d3);
    lcd->begin(displayconfig.cols, displayconfig.rows);
}

void DefenderMenu::display_animated_text(String text, int row, int step_ms) {
    int bufsize = displayconfig.cols+1;
    char char_text[bufsize];
    text.toCharArray(char_text, bufsize);

    for (int i = 0; i < (int) strlen(char_text); ++i) {
        lcd->setCursor(i, row);
        lcd->print(char_text[i]);
        delay(step_ms);
    }
}

void DefenderMenu::welcome_screen(int delay_seconds) {
    display_animated_text(String("  DEFENDER 110  "), 0, 100);
    display_animated_text(String("one life,live it"), 1, 100);

    delay(delay_seconds*1000);
    lcd->clear();
}

int DefenderMenu::type_of_current_page() {
    return pages[current_page]->get_page_type();
}

void DefenderMenu::update_lcd_gauge() {
    lcd->setCursor(0, 1);
    for (int i = 0; i < displayconfig.cols; i++)
        lcd->print((char)219); //(char)32);
    lcd->setCursor(0, 1);
    lcd->print(pages[current_page]->lcd_second_line().c_str());
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
    current_page = (current_page+1) % total_pages();
}