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

void Loading::render() const
{
    uint8_t symbols[8] = {0x00, 0x10, 0x18, 0x1C, 0x1E, 0x1F, 0xFF}; // 5%

    for (int cursor = 0; cursor < 95; cursor += 5)
    {
        int symbol = cursor + 5 > *percentage 
            ? 6 : cursor + 4 > *percentage 
            ? 5 : cursor + 3 > *percentage 
            ? 4 : cursor + 2 > *percentage 
            ? 3 : cursor + 1 > *percentage 
            ? 2 : cursor > *percentage 
            ? 1 : 0;

        uint8_t s[8] = {symbols[symbol], symbols[symbol], symbols[symbol], symbols[symbol], symbols[symbol], symbols[symbol], symbols[symbol] ,symbols[symbol]};
        lcd->createChar(0, s);
        lcd->setCursor(0, floor(*percentage/5));
        lcd->write(0);
    }

    *percentage += 1;
    // uint8_t col2[8] = {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18}; // 4%
    // uint8_t col3[8] = {0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C}; // 3%
    // uint8_t col4[8] = {0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E}; // 2%
    // uint8_t col5[8] = {0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F}; // 1%
    // uint8_t col6[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; // 0%

    // lcd->createChar(0, arrow);
    // lcd->setCursor(0, *percentage);
    // lcd->write(0);

    // for (int i = 0; i < 4; i++)
    // {
    //     lcd->setCursor(1, i);
    //     lcd->print(items->get(i).title);
    // }
}

void Loading::action(Stack<View> *views) const
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
