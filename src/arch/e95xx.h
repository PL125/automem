#ifndef E95xx_H
#define E95xx_H 

//#define SCK 13
#define CS 10
//#define OUT 11
//#define IN 12

#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1
#define READ 3
#define WRITE 2

#include <stdint.h>

class E95xx
{  
    private:
        int size;
    public:
        E95xx(int size);
        void setup();
        uint8_t read(int address);
        void write(int address, uint8_t data);
        void print();
};

#endif