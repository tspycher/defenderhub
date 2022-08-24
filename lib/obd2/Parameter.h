//
// Created by Thomas Spycher on 17.08.22.
//

#ifndef DEFENDERHUB_PARAMETER_H
#define DEFENDERHUB_PARAMETER_H

#include "OBDFacade.h"

#define CAN_ID_PID          0x7DF

class Parameter {
public:
    Parameter(OBDFacade &can);
    void load_block(unsigned char raw_data[]);
    bool request_from_obd(unsigned int timeout_ms=1000);
    int get_current_value();
    int get_previous_value();
    unsigned char get_pid();
    String get_pretty_value();
    String get_name();

    int get_maximum_value();
    int get_minimum_value();

protected:
    virtual int get_value() = 0;
    bool is_initialized;
    OBDFacade *can;

    int pid;
    String name;
    String unit;

    int previous_value;
    int current_value;
    int minimum_value;
    int maximum_value;
    int data_bytes;

    unsigned char *data[8];
    int get_a();
    int get_b();
    int get_c();
    int get_d();
};



#endif //DEFENDERHUB_PARAMETER_H
