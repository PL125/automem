#ifndef E95c_H
#define E95c_H 

//#define SCK 13
#define CS 10
//#define OUT 11
//#define IN 12

#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1

// #define READ 3
// #define WRITE 2

#include "e.h"

#include <Arduino.h>
#include <SPI.h>

class E95c : public E
{  
    private:
        int size;
    public:
        E95c(int size);
        // ~E95c();

        void setup() const;
        uint8_t read(uint16_t address) const;
        void write(uint16_t address, uint8_t data) const;
        void print() const;
};

// #define E95320 E95c(4096)

#endif