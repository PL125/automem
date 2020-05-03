#include "e24cxx.h"
#include <Arduino.h>

E24cxx::E24cxx(int size) {
    this->size = size;
}

void E24cxx::setup() {
    
}

uint8_t E24cxx::read(uint16_t address) {
    Wire.beginTransmission(0x50);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.endTransmission();

    Wire.requestFrom(0x50, 1);
    uint8_t result = 0;
    if (Wire.available())
        result = Wire.read();

    return result;

}

void E24cxx::write(int address, uint8_t data) {
    Wire.beginTransmission(0x50);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.write(data);
    Wire.endTransmission();
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
