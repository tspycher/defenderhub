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

Compass::Compass() {
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

void Compass::update_values() {
    course = 90;
}

String Compass::lcd_first_line() {
    //int steps = 5;
    //int left = (course - steps + 360) % 360;
    //int right = (course + steps) % 360;
    //int total = get_len(left) + get_len(course) + get_len(right);
    int total = get_len(course);
    String s;
    for (int x = 0; x < (16 - total) / 2; ++x)
        s += String(" ");
    //return String(left)+String(s)+String(course)+String(s)+String(right);
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