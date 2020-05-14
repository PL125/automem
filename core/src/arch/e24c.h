#ifndef E24C_H
#define E24C_H 

#include "e.h"

#include <Wire.h>

class E24c : public E
{  
    public:

        E24c(int sz, int addr);
        // ~E24c();

        void setup() const;
        uint8_t read(uint16_t address) const;
        void write(uint16_t address, uint8_t data) const;
        
        void dump() const;
        void print() const;

    private:

        int sz;
        int addr;
};

#endif