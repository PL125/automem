#include "misc/i4gv.h"

uint16_t I4gv::getImmoCode(E95xx *e) {
    uint8_t E7 = e->read(0xE7);
    uint8_t E6 = e->read(0xE6);

    uint16_t code = (E7<<8)|(E6);

    return code;
}