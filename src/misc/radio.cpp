#include "misc/radio.h"

char* Radio::getCode(E24cxx *e) {
    char result[5] = "";
    char a18[2] = "";
    char a19[2] = "";
    char a1a[2] = "";
    char a1b[2] = "";

    sprintf(a18, "%02x", e->read(0x18));
    result[0] = a18[1];
    sprintf(a19, "%02x", e->read(0x19));
    result[1] = a19[0];
    sprintf(a1a, "%02x", e->read(0x1a));
    result[2] = a1a[1];
    sprintf(a1b, "%02x", e->read(0x1b));
    result[3] = a1b[0];

    return result;
}

