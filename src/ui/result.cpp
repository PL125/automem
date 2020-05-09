#include "result.h"

char value[8];

Result::Result(LiquidCrystal_I2C *lcd, E *e, char* script)
{
    this->lcd = lcd;
    this->script = script;
    // this->value = new char();
    this->cursor = new int(0);
}

Result::~Result() {}

void Result::setup() const
{
    Parser::run(value, "(m (l (r 24)) (f (r 25)) (l (r 26)) (f (r 27)))");
}

void Result::render() const
{
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);
    lcd->createChar(2, Symbols::arrow_up);

    lcd->setCursor(1, 1);
    lcd->print("Codigo:");
    lcd->setCursor(1, 2);    
    lcd->print(value);
    lcd->setCursor(19, 3);
    lcd->write(1);

    lcd->setCursor(*cursor+1, 3);
    lcd->write(2);
    

}

void Result::action(LinkedList<View*> *views) const
{
    Controls c = Controls::getInstance();

    if (c.right->update() && c.right->rose())
    {
        lcd->setCursor(*cursor+1, 3);
        lcd->print(" ");
        *cursor += 1;
        *cursor %= 4;
    }

    if (c.left->update() && c.left->rose())
    {
        lcd->setCursor(*cursor+1, 3);
        lcd->print(" ");
        *cursor -= 1;
        if(*cursor < 0)
        {
            *cursor %= 0;
        }
    }

    if (c.enter->update() && c.enter->rose())
    {
        lcd->clear();
        views->pop();
    }

    if (c.back->update() && c.back->rose())
    {
        lcd->clear();
        views->pop();
    }
}
