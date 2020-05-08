#include "loading.h"

Loading::Loading(LiquidCrystal_I2C *lcd)
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
    this->percentage = new int(0);
}

Loading::~Loading() {}

void Loading::setup() const
{
    
}

void Loading::render() const
{
    
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);

    if (*percentage < 100)
    {
        lcd->setCursor(1, 1);
        lcd->print("Lendo...");

        uint8_t value = max(floor(*percentage/5)-1, 1);
        for (int i = 0; i < value; i++)
        {
            lcd->setCursor(value, 2);
            lcd->write(0);
        }

        *percentage += 1;
        if(*percentage == 100)
        {
            lcd->clear();
        }
    } else {
        lcd->setCursor(1, 1);
        lcd->print("Completo");
        lcd->setCursor(19, 3);
        lcd->write(1);
    }
}

void Loading::action(LinkedList<View> &views) const
{
    if (bouncer_enter->update() && bouncer_enter->rose())
    {
        lcd->clear();
        views.pop();
    }

    if (bouncer_back->update() && bouncer_back->rose())
    {
        lcd->clear();
        views.pop();
    }
}
