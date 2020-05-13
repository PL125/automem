#ifndef E24C_H
#define E24C_H 

#include "e.h"

#include <Arduino.h>
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

#endif