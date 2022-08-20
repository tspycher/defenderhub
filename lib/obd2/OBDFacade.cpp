//
// Created by Thomas Spycher on 20.08.22.
//

#include "OBDFacade.h"

OBDFacade::OBDFacade(bool isMocking) : is_mocking(isMocking) {
    if (isMocking) {
        obd_mock = new MockSerial_CAN();
        Serial.println("Loading Mock CAN BUS");
    } else {
        obd_real = new Serial_CAN();
        Serial.println("Loading Real CAN BUS");
    }
}

OBDFacade::~OBDFacade() {

}

bool OBDFacade::isMocking() {
    return is_mocking;
}


// OBD Methods
void OBDFacade::begin(int can_tx, int can_rx, unsigned long baud) {
    if (is_mocking) {
        obd_mock->begin(can_tx, can_rx, baud);
    } else {
        obd_real->begin(can_tx, can_rx, baud);
    }
}
/*
void OBDFacade::begin(SoftwareSerial &serial, unsigned long baud) {
    if (is_mocking) {
        obd_mock->begin(serial, baud);
    } else {
        obd_real->begin(serial, baud);
    }
}

void OBDFacade::begin(HardwareSerial &serial, unsigned long baud) {
    if (is_mocking) {
        obd_mock->begin(serial, baud);
    } else {
        obd_real->begin(serial, baud);
    }
}
*/

unsigned char OBDFacade::send(unsigned long id, uchar ext, uchar rtrBit, uchar len, const uchar *buf) {
    if (is_mocking) {
        return obd_mock->send(id, ext, rtrBit, len, buf);
    } else {
        return obd_real->send(id, ext, rtrBit, len, buf);
    }
}

unsigned char OBDFacade::recv(unsigned long *id, uchar *buf) {
    if (is_mocking) {
        return obd_mock->recv(id,  buf);
    } else {
        return obd_real->recv(id,  buf);
    }
}

/*
unsigned char OBDFacade::canRate(unsigned char rate) {
    if (is_mocking) {
        return obd_mock->canRate(rate);
    } else {
        return obd_real->canRate(rate);
    }
}



unsigned char OBDFacade::baudRate(unsigned char rate) {
    if (is_mocking) {
        return obd_mock->baudRate(rate);
    } else {
        return obd_real->baudRate(rate);
    }
}


unsigned char OBDFacade::setMask(unsigned long *dta) {
    if (is_mocking) {
        return obd_mock->setMask(dta);
    } else {
        return obd_real->setMask(dta);
    }
}

unsigned char OBDFacade::setFilt(unsigned long *dta) {
    if (is_mocking) {
        return obd_mock->setFilt(dta);
    } else {
        return obd_real->setFilt(dta);
    }
}
*/