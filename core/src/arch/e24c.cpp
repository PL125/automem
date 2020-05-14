#include "e24c.h"

E24c::E24c(int sz, int addr)
{
    this->sz = sz;
    this->addr = addr;
}

void E24c::setup() const
{
    Wire.begin(addr);
}

uint8_t E24c::read(uint16_t address) const
{
    Wire.beginTransmission(addr);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.endTransmission();

    Wire.requestFrom(addr, 1);
    uint8_t result = 0;
    if (Wire.available())
    {
        result = Wire.read();
    }

    return result;
}

void E24c::write(uint16_t address, uint8_t data) const
{
    Wire.beginTransmission(addr);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.write(data);
    Wire.endTransmission();
}

void E24c::dump() const
{

}