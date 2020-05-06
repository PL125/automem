#ifndef E_H
#define E_H 

#include <stdint.h>

class E
{  
    public:
        virtual ~E() {}

        virtual void setup() const = 0;
        virtual uint8_t read(uint16_t address) const = 0;
        virtual void write(uint16_t address, uint8_t data) const = 0;
        virtual void print() const = 0;
};

#endif