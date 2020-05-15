#ifndef E93c_H
#define E93c_H 

#define CLK 13
#define CS1 9
#define DI 11
#define DO 12

#define WREN 6
#define WRDI 4
#define RDSR 5
#define WRSR 1
#define READ 2
#define WRITE 5

#define HALF_CLOCK_PERIOD 100 // Microseconds

#include "e.h"


class E93c : public E
{  
    public:

        E93c(int sz, int addrsz, int pgsz);
        // ~E93c();

        void setup() const;
        uint8_t read(uint16_t address) const;
        void write(uint16_t address, uint8_t data) const;

        void dump() const;
        void print() const;

    private:
        
        int sz;
        int addrsz;
        int pgsz;

        long transmit(int data, int bits) const;
        void send_opcode(char op) const;

};

#endif