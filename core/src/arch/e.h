#ifndef E_H
#define E_H

#include <Arduino.h>
#include <stdint.h>


class E
{
public:
    virtual ~E(){};

    virtual void setup() const = 0;
    virtual void dump() const = 0;
    virtual uint8_t read(uint16_t address) const = 0;
    virtual void write(uint16_t address, uint8_t data) const = 0;

    void print()
    {
        char buf[128];

        for (int i = 0; i < sz; i++)
        {
            if ((i & 15) == 0)
            {
                sprintf(buf, "\n0x%03X: ", i);
                Serial.print(buf);
            }

            sprintf(buf, " 0x%02X: ", read(i));
            Serial.print(buf);
        }

        delay(5000);
    };

private:
    int sz;
};

#endif