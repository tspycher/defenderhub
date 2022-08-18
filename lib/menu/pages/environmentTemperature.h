//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
#define DEFENDERHUB_ENVIRONMENTTEMPERATURE_H

#include <Arduino.h>
#include <Page.h>
#include <sensorEnvironmentTemperature.h>

class EnvironmentTemperature : public Page {
public:
    ~EnvironmentTemperature();

    EnvironmentTemperature(int onewirebus);
    String lcd_first_line() override;
    String lcd_second_line() override;
private:
    SensorEnvironmentTemperature *sensor;
};

#endif //DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
