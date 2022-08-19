//
// Created by Thomas Spycher on 17.08.22.
//

#ifndef DEFENDERHUB_ENGINESPEED_H
#define DEFENDERHUB_ENGINESPEED_H

#include <Parameter.h>

class EngineSpeed : public Parameter {
public:
    EngineSpeed(Serial_CAN &can);
    int get_value() override;
};


#endif //DEFENDERHUB_ENGINESPEED_H
