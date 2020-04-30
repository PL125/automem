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

    pinMode(CS, OUTPUT);
    pinMode(SCK, OUTPUT);
    pinMode(DI, OUTPUT);
    pinMode(DO, INPUT);
}

//https://github.com/tim0s/MicrowireEEPROM
uint16_t E93xx::transmit(uint16_t data, uint8_t bits)
{
        int dout = 0;
        for (int i=(bits-1); i>=0; i--) {
                dout |= ((int) digitalRead(DO)) << i;
                if ((1 << i) & data) digitalWrite(DI, HIGH);
                else digitalWrite(DI, LOW);
                delayMicroseconds(HALF_CLOCK_PERIOD);
                digitalWrite(SCK, HIGH);
                delayMicroseconds(HALF_CLOCK_PERIOD);
                digitalWrite(SCK, LOW);
        }
        digitalWrite(DI, LOW);
        return dout;
}

void E93xx::send_opcode(uint8_t op)
{
        digitalWrite(SCK, HIGH);
        delayMicroseconds(HALF_CLOCK_PERIOD);
        digitalWrite(SCK, LOW);
        digitalWrite(CS, HIGH);
        digitalWrite(DI, HIGH);

        transmit((1 << 2) | op, 3);
}

uint8_t E93xx::read(uint16_t address) {

    // SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));

    // digitalWrite(CS, HIGH);

    // // READ SB
    // digitalWrite(DI, HIGH);

    // // READ OPCODE
    // digitalWrite(DI, HIGH);
    // digitalWrite(DI, LOW);

    // // 93xx USE 9 BITS FOR ADDRESS
    // digitalWrite(DI, address > 255 ? HIGH : LOW);
    // SPI.transfer(lowByte(address));

    // // GET BYTE
    // uint8_t result = SPI.transfer(0);
    
    // digitalWrite(CS, LOW); 
    
    // SPI.endTransaction();

    send_opcode(READ);
    transmit(address, 9);

    uint8_t result = transmit(0, 8+1);

    digitalWrite(CS, LOW); 
    
    return result;
}


void E93xx::read_all() {
    for(int i=0; i<size;i++) { 
        Serial.write(read(i)); 
    }
}

void E93xx::write(uint16_t address, uint8_t data) {
    SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));

    digitalWrite(CS, HIGH);

    // EWEN SB
    digitalWrite(DI, HIGH);

    // EWEN OPCODE
    digitalWrite(DI, LOW);
    digitalWrite(DI, LOW);

    // EWEN INPUT
    digitalWrite(DI, HIGH);
    SPI.transfer(255);

    digitalWrite(CS, LOW); 

    delay(3);

    digitalWrite(CS, HIGH);
    
    // WRITE SB
    digitalWrite(DI, HIGH);

    // WRITE OPCODE
    digitalWrite(DI, LOW);
    digitalWrite(DI, HIGH);

    // 93xx USE 9 BITS FOR ADDRESS
    digitalWrite(DI, address > 255 ? HIGH : LOW);
    SPI.transfer(lowByte(address));

    // DATA
    SPI.transfer(data);

    digitalWrite(CS, LOW); 

    delay(10);

    digitalWrite(CS, HIGH);

    // EWDS SB
    digitalWrite(DI, HIGH);

    // EWDS OPCODE
    digitalWrite(DI, LOW);
    digitalWrite(DI, LOW);

    // EWDS INPUT
    digitalWrite(DI, LOW);
    SPI.transfer(0);

    digitalWrite(CS, LOW); 

    delay(3);
    
    SPI.endTransaction();
}

void E93xx::print() {
    char buf[128];

    for(int i=0; i<size;i++) {
        // if((i&15)==0) {
        // sprintf(buf, "\n0x%03X: ", i);
        // Serial.print(buf);
        // }

        //sprintf(buf, "0x%02X: ", read(i));
        sprintf(buf, "0x%02X ", read(i));
        Serial.print(buf);
        delay(10);
    }

    Serial.print("\n\t");

    delay(5000);
}

