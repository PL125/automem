#include "arch/e24cxx.h"

class Radio
{
    public:
        static uint16_t getCode(E24cxx *e);

    private:
        Radio() {}
};