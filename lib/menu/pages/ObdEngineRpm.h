//
// Created by Thomas Spycher on 18.08.22.
//

#ifndef DEFENDERHUB_OBDENGINERPM_H
#define DEFENDERHUB_OBDENGINERPM_H

#include <Page.h>

class ObdEngineRpm : public Page {
public:
    ObdEngineRpm(Parameter &obd_parameter);
    ~ObdEngineRpm();
    String lcd_first_line() override;
    String lcd_second_line() override;
    int get_gauge_value() override;
protected:
    float get_obd_value();
};


#endif //DEFENDERHUB_OBDENGINERPM_H
