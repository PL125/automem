#include "e24cxx.h"

E24cxx::E24cxx(int size) {
    this->size = size;
}

void E24cxx::setup() {
    
}

uint8_t E24cxx::read(uint16_t address) {
    if (!i2c_start(EEPROMADDR | I2C_WRITE | (address&0x10000 ? 8 : 0) )) return false;

    if (!i2c_write((address>>8)&0xFF)) return false;
    if (!i2c_write(address&0xFF)) return false;

    if (!i2c_rep_start(EEPROMADDR | I2C_READ | (address&0x10000 ? 8 : 0) ))return false;

    uint8_t result = i2c_read(true);

    i2c_stop();

    return result;

}

void E24cxx::write(int address, uint8_t data) {
    
}

void E24cxx::print() {
    char buf[128];

    for(int i=0; i<size;i++) {
        if((i&15)==0) {
        sprintf(buf, "\n0x%03X: ", i);
        Serial.print(buf);
        }

        sprintf(buf, " 0x%02X: ", read(i));
        Serial.print(buf);
    }

    delay(5000);
}
