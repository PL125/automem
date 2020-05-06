#include "misc/radio.h"

char* Radio::getCode(E24cxx *e) {
    char *result = new char[4];
    char *temp = new char[2];
    
    sprintf(temp, "%02x", e->read(0x18));
    result[0] = temp[1];
    sprintf(temp, "%02x", e->read(0x19));
    result[1] = temp[0];
    sprintf(temp, "%02x", e->read(0x1a));
    result[2] = temp[1];
    sprintf(temp, "%02x", e->read(0x1b));
    result[3] = temp[0];
    
    return result;
}   

