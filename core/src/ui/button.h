#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button
{
public:
    Button(uint8_t pin, uint16_t debounceDelay);

    bool check();

private:
    const uint8_t _pin;
    bool _state;
    bool _lastState;
    uint32_t _lastMillis;
    uint16_t _debounceDelay;
    uint32_t _lastDebounceTime;
};

#endif