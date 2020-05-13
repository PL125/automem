#include "e24c.h"

E24c::E24c(int size, int id)
{
    this->size = size;
    this->id = id;
}

void E24c::setup() const
{
    Wire.begin(id);
}

uint8_t E24c::read(uint16_t address) const
{
    Wire.beginTransmission(id);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.endTransmission();

    Wire.requestFrom(id, 1);
    uint8_t result = 0;
    if (Wire.available())
    {
        result = Wire.read();
    }

    return result;
}

void E24c::write(uint16_t address, uint8_t data) const
{
    Wire.beginTransmission(id);
    Wire.write(address >> 8);
    Wire.write(address & 0xFF);
    Wire.write(data);
    Wire.endTransmission();
}

void E24c::print() const
{
    char buf[128];

    for (int i = 0; i < size; i++)
    {
        if ((i & 15) == 0)
        {
            sprintf(buf, "\n0x%03X: ", i);
            // Serial.print(buf);
        }

        sprintf(buf, " 0x%02X: ", read(i));
        // Serial.print(buf);
    }
}
