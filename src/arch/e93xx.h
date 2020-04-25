#ifndef E93xx_H
#define E93xx_H 

//#define SCK 13
#define CS 10
//#define OUT 11
#define DI 11
#define DO 12

//#define WREN 6
//#define WRDI 4
//#define RDSR 5
//#define WRSR 1
#define READ 6
#define WRITE 5

#include <stdint.h>

class E93xx
{  
    private:
        int size;
    public:
        E93xx(int size);
        void setup();
        uint8_t read(uint8_t address);
        void write(uint8_t address, uint8_t data);
        void print();
};

#endif