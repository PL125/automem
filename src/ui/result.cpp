#include "result.h"

Result::Result(LiquidCrystal_I2C *lcd, char *value)
{
    pinMode(ENTER, INPUT);
    pinMode(BACK, INPUT);

    bouncer_enter = new Bounce();
    bouncer_enter->attach(ENTER);
    bouncer_enter->interval(20);

    bouncer_back = new Bounce();
    bouncer_back->attach(BACK);
    bouncer_back->interval(20);

    this->lcd = lcd;
    this->value = value;
}

Result::~Result() {}

void Result::render() const
{
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);

    lcd->setCursor(1, 1);
    lcd->print("Codigo:");
    lcd->setCursor(1, 2);
    lcd->print(value);
    lcd->setCursor(19, 3);
    lcd->write(1);
}

void Result::action(Stack<View> *views) const
{
    if (bouncer_enter->update() && bouncer_enter->rose())
    {
        lcd->clear();
        views->pop();
    }

    if (bouncer_back->update() && bouncer_back->rose())
    {
        lcd->clear();
        views->pop();
    }
}
