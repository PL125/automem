#ifndef E24cxx_H
#define E24cxx_H 

#define SDA_PORT PORTC
#define SDA_PIN 4
#define SCL_PORT PORTC
#define SCL_PIN 5

#include <SoftI2CMaster.h>
#include <stdint.h>

#define EEPROMADDR 0xA6
#define MAXADDR 0x1FFFF
#define MAXTESTADDR 0x007FF

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