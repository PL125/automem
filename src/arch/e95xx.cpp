#include <Arduino.h>
#include <SPI.h>

#include "e95xx.h"


void E95xx::setup() {
    SPI.begin();
    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);
}

uint8_t E95xx::read(int address) {
    SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

    digitalWrite(CS, LOW);
    
    SPI.transfer(READ);
    SPI.transfer(address >> 8);
    SPI.transfer(address);

    uint8_t result = SPI.transfer(0);
    
    digitalWrite(CS, HIGH); 
    
    SPI.endTransaction();
    
    return result;
}

void E95xx::write(int address, uint8_t data) {
    SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

    digitalWrite(CS, LOW);
    SPI.transfer(WREN);
    digitalWrite(CS, HIGH);

    digitalWrite(CS, LOW);

    SPI.transfer(WRITE);
    SPI.transfer(address >> 8);
    SPI.transfer(address);

    SPI.transfer(data);
    
    digitalWrite(CS, HIGH); 
    
    SPI.endTransaction();
}

void E95xx::print() {
    char buf[128];

    for(int i=0; i<4096;i++) {
        if((i&15)==0) {
        sprintf(buf, "\n0x%03X: ", i);
        Serial.print(buf);
        }

        sprintf(buf, " 0x%02X: ", read(i));
        Serial.print(buf);
    }

    delay(5000);
}
