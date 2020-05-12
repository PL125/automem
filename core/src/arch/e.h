#ifndef E_H
#define E_H 

#include <stdint.h>

class E
{  
    public:
        virtual ~E() {};

        virtual void setup() {};
        virtual uint8_t read(uint16_t address) {};
        virtual void write(uint16_t address, uint8_t data) {};
        virtual void print() {};
};

#endif