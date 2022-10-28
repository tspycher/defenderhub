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

    // init Temperature sensors
    if(unitconfig.with_temperature) {
        /*oneWire = new OneWire(unitconfig.one_wire_bus_pin);
        sensors = new DallasTemperature(oneWire);
        sensors->begin();
         */
        temperature_ready = true;
        Serial.println("--> Temperature Sensors Initialized");
    } else {
        temperature_ready = false;
    }

}

float Car::get_temperature_for_index(uint8_t index) {
    //sensors->requestTemperatures();
    if (temperature_ready) {
        return 99.9;
    }
    return 21.5;
    sensors->requestTemperatures();
    float temp = sensors->getTempCByIndex(index);
    Serial.print("Requested Temperature at Index ");
    Serial.print(index);
    Serial.print(" which reads ");
    Serial.print(temp);
    Serial.println("C");
    return temp;
}

bool Car::is_gps_ready() {
    return gps_ready;
}

TinyGPSPlus* Car::get_gps() {
    return gps;
}

UnitConfig& Car::get_unitconfig() {
    return unitconfig;
}

double Car::get_temperature_inside() {
    return get_temperature_for_index(unitconfig.temperature_index_inside);
}

double Car::get_temperature_outside() {
    return get_temperature_for_index(unitconfig.temperature_index_outside);
}

void Car::update_gps(bool debug=false, int timeout_seconds=2) {
    if(!gps_ready)
        return;
    /*unsigned long timeout_timer_start = millis();
    while (gps_serial->available() > 0) {
        if (millis() - timeout_timer_start >= (unsigned long)(timeout_seconds*1000)) {
            Serial.println("Hitting timeout in updating GPS");
            break;
        }
        unsigned char raw_gps_data = gps_serial->read();
        gps->encode(raw_gps_data);
        if (debug)
            Serial.write(raw_gps_data);
    }
    Serial.print("Latitude: ");
    Serial.print(gps->location.lat());
    Serial.print(" Longitude: ");
    Serial.println(gps->location.lng());*/

    while (gps_serial->available() > 0)
        gps->encode(gps_serial->read());
}

double Car::get_latitude(){
    return gps->location.lat();
}

double Car::get_longitude(){
    return gps->location.lng();
}

double Car::get_gpsspeed(){
    return gps->speed.kmph();
}

double Car::get_altitude() {
    return gps->altitude.meters();
}

double Car::get_course(){
    return gps->course.deg();
}

int Car::get_satellites(){
    return gps->satellites.value();
}

bool Car::is_gps_updated() {
    if (gps->altitude.isUpdated() || gps->satellites.isUpdated() || gps->location.isUpdated())
        return true;
    return false;
}