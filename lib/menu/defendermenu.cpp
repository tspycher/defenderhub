//
// Created by Thomas Spycher on 02.08.22.
//

#include "defendermenu.h"
#include "pages/environmentTemperature.h"
#include "pages/obdOil.h"
#include "pages/gpsPosition.h"
#include "pages/consumption.h"
#include "pages/ObdEngineRpm.h"
#include "pages/trip.h"
#include "sound.h"

DefenderMenu::DefenderMenu(struct UnitConfig unitconfig) : unitconfig(unitconfig), is_defender_green(true){
    obd = new DefenderObd2(unitconfig.mock_can);

    //Parameter *obd_oil = obd->get_parameter(0x5C);
    Parameter *obd_rpm = obd->get_parameter(0x0C);

    pages[0] = new ObdEngineRpm(*obd_rpm);
    pages[1] = new EnvironmentTemperature(unitconfig.one_wire_bus_pin);

    //pages[2] = new ObdOil(*obd_oil);
    pages[2] = new GpsPosition();
    pages[3] = new Consumption();
    pages[4] = new Trip();

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

void DefenderMenu::welcome_screen(int delay_seconds, bool with_music) {
    display_animated_text(String("  DEFENDER 110  "), 0, 30);
    display_animated_text(String("one life,live it"), 1, 40);

    if (with_music) {
        Sound s;
        s.play_welcome();
    }
    delay(delay_seconds*1000);
    lcd->clear();
}

int DefenderMenu::type_of_current_page() {
    return pages[current_page]->get_page_type();
}

void DefenderMenu::update_lcd_gauge() {
    lcd->setCursor(0, 0);

    String first_line = pages[current_page]->lcd_first_line();
    lcd->send_string(first_line.c_str());
    if (first_line.length() < (unsigned int)unitconfig.lcd_cols) {
        for (int i = first_line.length(); i < unitconfig.lcd_cols; ++i) {
            lcd->write_char((char)32);
        }
    }

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

void DefenderMenu::switch_page(int page) {
    current_page = page % total_pages();
}

void DefenderMenu::switch_page() {
    current_page = (current_page+1) % total_pages();
    Sound s;
    s.play_page_switch();
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