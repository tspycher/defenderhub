//
// Created by Thomas Spycher on 20.08.22.
//

#ifndef DEFENDERHUB_OBDFACADE_H
#define DEFENDERHUB_OBDFACADE_H

#include <MockSerial_CAN_Module.h>
#include <Serial_CAN_Module.h>

class OBDFacade {
public:
    OBDFacade(bool isMocking);
    bool isMocking();
    virtual ~OBDFacade();

    // OBD Methods
    void begin(int can_tx, int can_rx, unsigned long baud);
    //void begin(SoftwareSerial &serial, unsigned long baud);
    //void begin(HardwareSerial &serial, unsigned long baud);
    unsigned char send(unsigned long id, uchar ext, uchar rtrBit, uchar len, const uchar *buf);
    unsigned char recv(unsigned long *id, uchar *buf);

    //unsigned char canRate(unsigned char rate);
    //unsigned char baudRate(unsigned char rate);

    //unsigned char setMask(unsigned long *dta);
    //unsigned char setFilt(unsigned long *dta);
private:
    bool is_mocking;
    MockSerial_CAN *obd_mock;
    Serial_CAN *obd_real;
};


#endif //DEFENDERHUB_OBDFACADE_H
