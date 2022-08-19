//
// Created by Thomas Spycher on 17.08.22.
//

#ifndef DEFENDERHUB_OILTEMPERATURE_H
#define DEFENDERHUB_OILTEMPERATURE_H

#include <Parameter.h>


class OilTemperature : public Parameter{
public:
    OilTemperature(Serial_CAN &can);
    int get_value() override;
};


#endif //DEFENDERHUB_OILTEMPERATURE_H
