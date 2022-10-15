//
// Created by Thomas Spycher on 14.10.22.
//

#include "Version.h"
#include "versiondetails.h"

int Version::refreshrate_seconds() {
    return 500;
}

String Version::lcd_first_line() {
    return String(BUILDTIME);
}

String Version::lcd_second_line() {
    return String(VERSION);
}