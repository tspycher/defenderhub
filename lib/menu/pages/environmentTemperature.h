//
// Created by Thomas Spycher on 02.08.22.
//

#ifndef DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
#define DEFENDERHUB_ENVIRONMENTTEMPERATURE_H

#include <Page.h>
#include <sensorEnvironmentTemperature.h>

class EnvironmentTemperature : public Page {
public:
    EnvironmentTemperature(int onewirebus);
    String lcd_first_line() override;
    String lcd_second_line() override;
    void update_values() override;
private:
    SensorEnvironmentTemperature *sensor;
    float tmp_inside;
    float tmp_outside;
    int age;
};

#endif //DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
