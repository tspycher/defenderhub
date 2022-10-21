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
    void draw_on_oled_screen(Adafruit_SSD1351 oled, int oled_width, int oled_heigh) override;

    void update_values() override;
    int refreshrate_seconds() override;
    bool needs_lcd_update() override;

private:
    SensorEnvironmentTemperature *sensor;
    float tmp_inside = 0.0;
    float tmp_outside= 0.0 ;
    float previous_tmp_inside;
    float previous_tmp_outside;
};

#endif //DEFENDERHUB_ENVIRONMENTTEMPERATURE_H
