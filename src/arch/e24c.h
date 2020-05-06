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
        void setup();
        uint8_t read(uint16_t address);
        void write(int address, uint8_t data);
        void print();
};

#define E24c32 E24c(4096, 0x50)

#endif