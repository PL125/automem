#include "e93c.h"

E93c::E93c(int size, int address_size, int page_size)
{
    this->size = size;
    this->address_size = address_size;
    this->page_size = page_size;

    setup();
}

void E93c::setup() const
{
    pinMode(CS, OUTPUT);
    pinMode(CLK, OUTPUT);
    pinMode(DI, OUTPUT);
    pinMode(DO, INPUT);
}

//https://github.com/tim0s/MicrowireEEPROM
uint16_t E93c::transmit(uint16_t data, uint8_t bits) const
{
    int dout = 0;
    for (int i = (bits - 1); i >= 0; i--)
    {
        dout |= ((int)digitalRead(DO)) << i;
        if ((1 << i) & data)
            digitalWrite(DI, HIGH);
        else
            digitalWrite(DI, LOW);
        delayMicroseconds(HALF_CLOCK_PERIOD);
        digitalWrite(CLK, HIGH);
        delayMicroseconds(HALF_CLOCK_PERIOD);
        digitalWrite(CLK, LOW);
    }
    digitalWrite(DI, LOW);
    return dout;
}

void E93c::send_opcode(uint8_t op) const
{
    digitalWrite(CLK, HIGH);
    delayMicroseconds(HALF_CLOCK_PERIOD);
    digitalWrite(CLK, LOW);
    digitalWrite(CS, HIGH);
    digitalWrite(DI, HIGH);

    transmit((1 << 2) | op, 3);
}

uint8_t E93c::read(uint16_t address) const
{
    setup();
    send_opcode(READ);
    transmit(address, 9);

    long result = transmit(0, 8 + 1);

    digitalWrite(CS, LOW);

    return result;
}

void E93c::read_all() const
{
    for (int i = 0; i < size; i++)
    {
        // Serial.write(read(i));
    }
}

void E93c::write(uint16_t address, uint8_t data) const
{

    send_opcode(0);
    transmit(0xFF, 9);
    digitalWrite(CS, LOW);

    send_opcode(1);
    transmit(address, 9);
    transmit(data, 8);
    digitalWrite(CS, LOW);

    send_opcode(0);
    transmit(0x00, 9);
    digitalWrite(CS, LOW);

    delay(10);
}

void E93c::print() const
{
    char buf[128];

    for (int i = 0; i < size; i++)
    {
        // if((i&15)==0) {
        // sprintf(buf, "\n0x%03X: ", i);
        // Serial.print(buf);
        // }

        //sprintf(buf, "0x%02X: ", read(i));
        sprintf(buf, "0x%02X ", read(i));
        // Serial.print(buf);
        delay(10);
    }

    // Serial.print("\n\t");

    delay(5000);
}
