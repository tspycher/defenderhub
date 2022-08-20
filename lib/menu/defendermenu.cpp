//
// Created by Thomas Spycher on 02.08.22.
//

#include "defendermenu.h"


DefenderMenu::DefenderMenu(struct UnitConfig unitconfig) : unitconfig(unitconfig), is_defender_green(true){
    obd = new DefenderObd2(true);

    Parameter *obd_oil = obd->get_parameter(0x5C);
    Parameter *obd_rpm = obd->get_parameter(0x0C);

    pages[0] = new ObdEngineRpm(*obd_rpm);
    pages[1] = new ObdOil(*obd_oil);
    pages[2] = new EnvironmentTemperature(unitconfig.one_wire_bus_pin);
    pages[3] = new GpsPosition();
    pages[4] = new Consumption();
    pages[5] = new Trip();

    lcd = new Waveshare_LCD1602_RGB(unitconfig.lcd_cols,unitconfig.lcd_rows);  //16 characters and 2 lines of show
    lcd->init();
    lcd->noCursor();
    lcd->setRGB(unitconfig.lcd_red, unitconfig.lcd_green, unitconfig.lcd_blue);
}

void DefenderMenu::update_current_page_data() {
    pages[current_page]->update_values();
}

Page *DefenderMenu::get_current_page() {
    return pages[current_page];
}

void DefenderMenu::show_message(char *message, int delay_ms) {
    lcd->clear();
    lcd->blink();
    lcd->noCursor();
    lcd->setCursor(0, 0);
    display_animated_text(String("*** MESSAGE ****"), 0, 50);
    lcd->setCursor(0, 1);
    lcd->send_string(message);
    delay(delay_ms);
    update_lcd();
}

void DefenderMenu::display_animated_text(String text, int row, int step_ms) {
    int bufsize = unitconfig.lcd_cols+1;
    char char_text[bufsize];
    text.toCharArray(char_text, bufsize);

    for (int i = 0; i < (int) strlen(char_text); ++i) {
        lcd->setCursor(i, row);
        lcd->write_char(char_text[i]);
        delay(step_ms);
    }
}

void DefenderMenu::welcome_screen(int delay_seconds) {
    display_animated_text(String("  DEFENDER 110  "), 0, 50);
    display_animated_text(String("one life,live it"), 1, 80);

    delay(delay_seconds*1000);
    lcd->clear();
}

int DefenderMenu::type_of_current_page() {
    return pages[current_page]->get_page_type();
}

void DefenderMenu::update_lcd_gauge() {
    lcd->setCursor(0, 1);
    int lcd_gauge_value = (int) (unitconfig.lcd_cols/ 100.0 * (float)pages[current_page]->get_gauge_value());

    char filler = 255;
    char empty = 219;

    String gauge;

    for (int i = 0; i < unitconfig.lcd_cols; i++) {
        if(i<= lcd_gauge_value) {
            lcd->write_char(filler); //(char)32);
        } else {
            lcd->write_char(empty); //(char)32);
        }
    }
}

void DefenderMenu::update_lcd(void) {
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

void DefenderMenu::special_option() {
    if (is_defender_green) {
        lcd->setRGB(100, 0 ,0);
        is_defender_green = false;
    } else {
        lcd->setRGB(unitconfig.lcd_red, unitconfig.lcd_green, unitconfig.lcd_blue);
        is_defender_green = true;

    }
}

void DefenderMenu::extra_special_option() {
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->send_string("Tom Spycher");
    lcd->setCursor(0, 1);
    lcd->send_string("August 2022");
}