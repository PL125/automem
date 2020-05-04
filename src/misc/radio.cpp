#include "misc/radio.h"

char* Radio::getCode(E24cxx *e) {
    char result[10];
    char a18[2];
    char a19[2];
    char a1a[2];
    char a1b[2];

    sprintf(a18, "%02X", e->read(0x18));
    sprintf(a19, "%02X", e->read(0x19));
    sprintf(a1a, "%02X", e->read(0x1a));
    sprintf(a1b, "%02X", e->read(0x1b));
    sprintf(result, "%c%c%c%c", a18[1], a19[0], a1a[1], a1b[0]);

    return result;
}

