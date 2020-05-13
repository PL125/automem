#ifndef E_H
#define E_H 

#include <stdint.h>

class E
{  
    public:
        virtual ~E() {};

        virtual void setup() const;
        virtual void dump() const;
        virtual uint8_t read(uint16_t address) const;
        virtual void write(uint16_t address, uint8_t data) const;
        virtual void print() const;
};

#endif