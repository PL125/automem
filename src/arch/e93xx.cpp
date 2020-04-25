#include <Arduino.h>
#include <SPI.h>

#include "e93xx.h"

E93xx::E93xx(int s) {
    size = s;
}

void E93xx::setup() {
    SPI.begin();
    pinMode(CS, OUTPUT);
    digitalWrite(CS, LOW);
}

uint8_t E93xx::read(uint8_t address) {
    SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

    digitalWrite(CS, HIGH);

    digitalWrite(DI, HIGH);
    digitalWrite(DI, HIGH);
    digitalWrite(DI, LOW);

    //SPI.transfer(READ);
    SPI.transfer(address);
    uint8_t result = SPI.transfer(0);
    
    digitalWrite(CS, LOW); 
    
    SPI.endTransaction();
    
    return result;
}

void E93xx::write(uint8_t address, uint8_t data) {
    SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

    digitalWrite(CS, HIGH);
    digitalWrite(DI, HIGH);
    digitalWrite(DI, LOW);
    digitalWrite(DI, LOW);
    digitalWrite(DI, HIGH);
    SPI.transfer(128);
    digitalWrite(CS, LOW);

    digitalWrite(CS, HIGH);

    //SPI.transfer(WRITE);

    digitalWrite(DI, HIGH);
    digitalWrite(DI, LOW);
    digitalWrite(DI, HIGH);

    SPI.transfer(address);
    SPI.transfer(data);

    digitalWrite(CS, LOW); 

    digitalWrite(CS, HIGH);
    digitalWrite(DI, HIGH);
    digitalWrite(DI, LOW);
    digitalWrite(DI, LOW);
    digitalWrite(DI, LOW);
    SPI.transfer(0);
    digitalWrite(CS, LOW);
    
    SPI.endTransaction();
}

void E93xx::print() {
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
