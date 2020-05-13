#ifndef E93c_H
#define E93c_H 

#define CLK 13 // 14
#define CS 10 // 15
//#define OUT 11
#define DI 11 // 13
#define DO 12

#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1
#define READ 2
#define WRITE 5

#define CLOCK 2000000
#define HALF_CLOCK_PERIOD 100 // Microseconds

#include "e.h"

#include <Arduino.h>
#include <SPI.h>

class E93c : public E
{  
    private:
        
        int address_size;
        int page_size;
    public:
        E93c(int size, int address_size, int page_size);
        // ~E93c();
        int size;
        void setup() const;
        uint8_t read(uint16_t address) const;
        uint16_t transmit(uint16_t data, uint8_t bits) const;
        void send_opcode(uint8_t op) const;
        void dump() const;
        void write(uint16_t address, uint8_t data) const;
        void print() const;
};

#endif