#ifndef E_H
#define E_H 

#include <stdint.h>

class E
{  
    private:
        int size;
    public:
        void setup();
        uint8_t read(uint16_t address);
        void write(uint16_t address, uint8_t data);
        void print();
};

#endif