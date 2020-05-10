#ifndef E24C_H
#define E24C_H 

#include "e.h"
#include <Wire.h>

class E24c : public E
{  
    private:
        int size;
        int id;
    public:
        E24c(int size, int id);
        // ~E24c();

        void setup() const;
        uint8_t read(uint16_t address) const;
        void write(uint16_t address, uint8_t data) const;
        void print() const;
};

#define E24c32 E24c(4096, 0x50)

#endif