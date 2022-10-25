//
// Created by Thomas Spycher on 25.10.22.
//

#include "Car.h"
Car::Car(struct UnitConfig &unitconfig) : unitconfig(unitconfig) {
    gps_serial = new SoftwareSerial(unitconfig.gps_tx, unitconfig.gps_rx);
    gps = new TinyGPSPlus();
    Serial.println("--> GPS Configured");

    // init GPS
    gps_serial->begin(unitconfig.gps_baud);
    gps_ready = true;
    Serial.println("--> GPS Initialized");
}
bool Car::is_gps_ready() {
    return gps_ready;
}

TinyGPSPlus* Car::get_gps() {
    return gps;
}

UnitConfig* Car::get_unitconfig() {
    return &unitconfig;
}

double Car::get_temperature_inside() {
    return 21.5;
}

double Car::get_temperature_outside() {
    return 4.3;
}

void Car::update_gps(bool debug) {
    if(!gps_ready)
        return;

    while (gps_serial->available() > 0) {
        unsigned char raw_gps_data = gps_serial->read();
        gps->encode(raw_gps_data);
        if (debug)
            Serial.write(raw_gps_data);
    }
    Serial.print("Latitude: ");
    Serial.print(gps->location.lat());
    Serial.print(" Longitude: ");
    Serial.println(gps->location.lng());
}