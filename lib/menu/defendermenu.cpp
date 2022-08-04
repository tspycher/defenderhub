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
#include "Waveshare_LCD1602_RGB.h"
#include <Arduino.h>


DefenderMenu::DefenderMenu(struct DisplayConfig displayconfig) : displayconfig(displayconfig){
    pages[0] = new Boost();
    pages[1] = new EnvironmentTemperature();
    pages[2] = new ObdOil();
    pages[3] = new GpsPosition();
    pages[4] = new Consumption();
    pages[5] = new Trip();

    lcd = new Waveshare_LCD1602_RGB(displayconfig.cols,displayconfig.rows);  //16 characters and 2 lines of show
    lcd->init();

    /*lcd.setCursor(0,0);
    lcd.send_string("Waveshare");
    lcd.setCursor(0,1);
    lcd.send_string("Hello,World!");
    */
}

void DefenderMenu::display_animated_text(String text, int row, int step_ms) {
    int bufsize = displayconfig.cols+1;
    char char_text[bufsize];
    text.toCharArray(char_text, bufsize);

    for (int i = 0; i < (int) strlen(char_text); ++i) {
        lcd->setCursor(i, row);
        lcd->write_char(char_text[i]);
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
    int lcd_gauge_value = (int) (displayconfig.cols/ 100.0 * (float)pages[current_page]->get_gauge_value());

    char filler = 255;
    char empty = 219;

    String gauge;

    for (int i = 0; i < displayconfig.cols; i++) {
        if(i<= lcd_gauge_value) {
            lcd->write_char(filler); //(char)32);
        } else {
            lcd->write_char(empty); //(char)32);
        }
    }
}

void DefenderMenu::update_lcd(void) {
    Serial.println("Updating LCD");
    lcd->clear();

    lcd->setCursor(0, 0);
    lcd->send_string(pages[current_page]->lcd_first_line().c_str());
    lcd->setCursor(0, 1);
    lcd->send_string(pages[current_page]->lcd_second_line().c_str());

}

int DefenderMenu::total_pages() {
    return sizeof(pages)/sizeof(pages[0]);
}

void DefenderMenu::switch_page() {
    current_page = (current_page+1) % total_pages();
}