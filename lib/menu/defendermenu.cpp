//
// Created by Thomas Spycher on 02.08.22.
//

#include "defendermenu.h"
#include "pages/environmentTemperature.h"
#include "pages/gpsPosition.h"
#include "pages/version.h"
#include "sound.h"

DefenderMenu::DefenderMenu(struct UnitConfig unitconfig) : unitconfig(unitconfig) {
    pages[0] = new EnvironmentTemperature(unitconfig.one_wire_bus_pin);
    pages[1] = new GpsPosition();
    pages[2] = new Version();
    num_pages = 3; //sizeof(&pages)/sizeof(pages[0]);

    lcd = new Waveshare_LCD1602_RGB(unitconfig.lcd_cols,unitconfig.lcd_rows);  //16 characters and 2 lines of show
    lcd->init();
    lcd->noCursor();
    lcd->setRGB(unitconfig.lcd_red, unitconfig.lcd_green, unitconfig.lcd_blue);

    sound = new Sound(unitconfig.piezo_pin);
}

void DefenderMenu::update_current_page_data() {
    get_page()->update_values();
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
    display_animated_text(String("  DEFENDER 110  "), 0, 30);
    display_animated_text(String("one life,live it"), 1, 40);

    if (unitconfig.with_sound) {
        sound->play_welcome();
    }
    delay(delay_seconds*1000);
    lcd->clear();
}

int DefenderMenu::type_of_current_page() {
    return get_page()->get_page_type();
}

Page * DefenderMenu::get_page() {
    return pages[current_page];
}

void DefenderMenu::update_lcd_gauge() {
    lcd->setCursor(0, 0);

    String first_line = get_page()->lcd_first_line();
    lcd->send_string(first_line.c_str());
    if (first_line.length() < (unsigned int)unitconfig.lcd_cols) {
        for (int i = first_line.length(); i < unitconfig.lcd_cols; ++i) {
            lcd->write_char((char)32);
        }
    }

    lcd->setCursor(0, 1);
    int lcd_gauge_value = (int) (unitconfig.lcd_cols/ 100.0 * (float)get_page()->get_gauge_value());

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

void DefenderMenu::update_lcd() {
    Serial.println("updating lcd...");
    get_page()->update_values();

    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->send_string(get_page()->lcd_first_line().c_str());
    lcd->setCursor(0, 1);
    lcd->send_string(get_page()->lcd_second_line().c_str());
}

int DefenderMenu::total_pages() {
    return num_pages;
}

int DefenderMenu::get_current_page() {
    return current_page;
}

void DefenderMenu::switch_page(int page) {
    current_page = page % total_pages();
}

void DefenderMenu::switch_page() {
    Serial.println(total_pages());
    current_page = (current_page+1) % total_pages();
    if (unitconfig.with_sound)
        sound->play_page_switch();
}

void DefenderMenu::switch_page_by_interrupt() {
    interrupt_switch_page = true;
}

void DefenderMenu::perform_interrupt_switch_page() {
    if (interrupt_switch_page) {
        interrupt_switch_page = false;
        switch_page();
        update_lcd();
    }
}
