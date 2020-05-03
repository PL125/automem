#ifndef E24cxx_H
#define E24cxx_H 

#include <Wire.h>

class E24cxx
{  
    private:
        int size;
    public:
        E24cxx(int size);
        void setup();
        uint8_t read(uint16_t address);
        void write(int address, uint8_t data);
        void print();
};

#endif