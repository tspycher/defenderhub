//
// Created by Thomas Spycher on 17.08.22.
//

#ifndef DEFENDERHUB_ABSOLUTEBAROMETRICPRESSURE_H
#define DEFENDERHUB_ABSOLUTEBAROMETRICPRESSURE_H

#include <Parameter.h>

class AbsoluteBarometricPressure : public Parameter {
public:
    AbsoluteBarometricPressure(MockSerial_CAN &can);
    int get_value() override;
};


#endif //DEFENDERHUB_ABSOLUTEBAROMETRICPRESSURE_H
