#include "e93c.h"

E93c::E93c(int sz, int addrsz, int pgsz)
{
    this->sz = sz;
    this->addrsz = addrsz;
    this->pgsz = pgsz;
}

void E93c::setup() const
{
    pinMode(CS1, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(DI, OUTPUT);
    pinMode(DO, INPUT);
}

uint8_t E93c::read(uint16_t address) const
{
    send_opcode(READ);
    transmit(address, addrsz);

    long result = transmit(0, pgsz+1);

    digitalWrite(CS1, LOW);

    return result;
}

void E93c::write(uint16_t address, uint8_t data) const
{
    send_opcode(0);
    transmit(0xFFFF, addrsz);
    digitalWrite(CS1, LOW);

    send_opcode(1);
    transmit(address, addrsz);
    transmit(data, pgsz);
    digitalWrite(CS1, LOW);

    send_opcode(0);
    transmit(0x0000, addrsz);
    digitalWrite(CS1, LOW);

    delay(10);
}

void E93c::dump() const
{
    for (int i = 0; i < sz; i++)
    {
        Serial.write(read(i));
    }
}

//https://github.com/tim0s/MicrowireEEPROM
long E93c::transmit(int data, int bits) const
{
    int dout = 0;
    for (int i = (bits - 1); i >= 0; i--)
    {
        dout |= ((int)digitalRead(DO)) << i;
        if ((1 << i) & data)
        {
            digitalWrite(DI, HIGH);
        }
        else
        {
            digitalWrite(DI, LOW);
        }
        delayMicroseconds(HALF_CLOCK_PERIOD);
        digitalWrite(CLK, HIGH);
        delayMicroseconds(HALF_CLOCK_PERIOD);
        digitalWrite(CLK, LOW);
    }
    digitalWrite(DI, LOW);
    return dout;
}

void E93c::send_opcode(char op) const
{
    digitalWrite(CLK, HIGH);
    delayMicroseconds(HALF_CLOCK_PERIOD);
    digitalWrite(CLK, LOW);
    digitalWrite(CS1, HIGH);
    digitalWrite(DI, HIGH);

    transmit((1 << 2) | op, 3);
}
