#include "button.h"

Button::Button(uint8_t pin, uint16_t debounceDelay = 50)
    : _pin(pin), _state(LOW), _lastState(LOW),
      _lastMillis(0), _debounceDelay(debounceDelay),
      _lastDebounceTime(0)
{
    pinMode(_pin, INPUT);
}

bool Button::check()
{
    bool reading = digitalRead(_pin);

    if (reading != _lastState)
    {
        _lastDebounceTime = millis();
    }

    if ((millis() - _lastDebounceTime) > _debounceDelay)
    {

        if (reading != _state)
        {
            _state = reading;
            return _state;
        }
    }
    _lastState = reading;

    return LOW;
}
