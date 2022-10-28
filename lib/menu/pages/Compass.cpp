//
// Created by Thomas Spycher on 15.10.22.
//

#include "Compass.h"

unsigned int get_len(int n) {
    unsigned int number_of_digits = 0;

    do {
        ++number_of_digits;
        n /= 10;
    } while (n);
    return number_of_digits;
}
int int_at_position(int n, int p) {
    int pp = 1;
    for(int x = 0; x < p; ++x) {
        pp *= 10;
    }
    pp /= 10;
    return n / pp;
}

Compass::Compass(Car& car) : Page(car), course(1) {
    for (int i = 0; i < 360; ++i) {
        if(i == 0) {
            needle[i] = "N";
        } else if(i == 90) {
            needle[i] = "E";
        } else if(i == 180) {
            needle[i] = "S";
        } else if(i == 270) {
            needle[i] = "W";
        }  else if (i % 5 == 0) {
            needle[i] = "|";
        } else {
            needle[i] = ".";
        }
    }
}

bool Compass::needs_display_update() {
    if (previous_course != course) {
        return true;
    }
    return false;
}

int Compass::refreshrate_seconds() {
    return 5;
}

void Compass::update_values() {
    previous_course = course;
    course = (course + 1) % 360;
}

String Compass::lcd_first_line() {
    int total = get_len(course);
    String s;
    for (int x = 0; x < (16 - total) / 2; ++x)
        s += String(" ");
    return String(s)+String(course)+(char)223;
}

String Compass::lcd_second_line() {
    char n[16];
    for(int i = -8; i < 8; ++i) {
        int j = (course+i+360) % 360;
        n[i+8] = *needle[j];
    }
    return String(n);
}

void Compass::draw_on_oled_screen(Adafruit_SSD1351 &oled, int oled_width, int oled_heigh) {

}