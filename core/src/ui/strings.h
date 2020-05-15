#ifndef STRINGS_H
#define STRINGS_H

#include <Arduino.h>

char* getString(const char* s)
{
    volatile const int len = strlen_P(s);

    char* buf = new char[len];
    for (uint8_t i = 0; i < len; i++) {
        buf[i] = pgm_read_byte_near(s + i);
    }
    buf[len] = '\0';

    return buf;
}

const char m0[] PROGMEM = "Imobilizador";
const char m1[] PROGMEM = "Airbag";
const char m2[] PROGMEM = "Odometro";
const char m3[] PROGMEM = "Radio";
const char m4[] PROGMEM = "Configuracoes";
const char m5[] PROGMEM = "Volkswagen";
const char m6[] PROGMEM = "Fiat";
const char m7[] PROGMEM = "Gol G4 (93c66)";
const char m8[] PROGMEM = "(z (/ (n (m (r 3) (r 2) (r 1) (r 0))) 10) f06ld)";
const char m9[] PROGMEM = "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))";

#endif