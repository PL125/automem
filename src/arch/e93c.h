#ifndef E93c_H
#define E93c_H 

#define CLK 13
#define CS 10
//#define OUT 11
#define DI 11
#define DO 12

#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1
#define READ 2
#define WRITE 5

#define CLOCK 2000000
#define HALF_CLOCK_PERIOD 100 // Microseconds

#include <stdint.h>

class E93c
{  
    private:
        int size;
        int address_size;
        int page_size;
    public:
        E93c(int size, int address_size, int page_size);
        void setup();
        uint8_t read(uint16_t address);
        uint16_t transmit(uint16_t data, uint8_t bits);
        void send_opcode(uint8_t op);
        void read_all();
        void write(uint16_t address, uint8_t data);
        void print();
};

const E93c E93c66 = E93c(512, 9, 8);

#endif