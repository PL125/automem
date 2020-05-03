#include "loading.h"

Loading::Loading(LiquidCrystal_I2C *lcd) {
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

void Loading::render() const {
    uint8_t arrow[8] = {0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00};
    lcd->createChar(0, arrow);
    lcd->setCursor(0, *percentage);
    lcd->write(0);

    // for (int i = 0; i < 4; i++)
    // {
    //     lcd->setCursor(1, i);
    //     lcd->print(items->get(i).title);
    // }
}

void Loading::action(Stack<View> *views) const {
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
