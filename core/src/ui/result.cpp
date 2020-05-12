#include "result.h"
#include <MemoryFree.h>

char value[16];
char aux[16];

void update()
{
    char aux[128];
    // sprintf(aux, "(w 0 (m (p 6 (z (* %s 10) f08x)) (p 7 (z (* %s 10) f08x))))", value);
    Parser::run(aux, "(w 0 (m (p 6 (z (* 150000 10) f08x)) (p 7 (z (* 150000 10) f08x))))");
    // Serial.println(aux);
    
    delay(100);

    // sprintf(aux, "(w 1 (m (p 4 (z (* %s 10) f08x)) (p 5 (z (* %s 10) f08x))))", value);
    
    Parser::run(aux, "(w 1 (m (p 4 (z (* 150000 10) f08x)) (p 5 (z (* 150000 10) f08x))))");

    delay(100);

    // Serial.println(aux);

    // sprintf(aux, "(w 2 (m (p 2 (z (* %s 10) f08x)) (p 3 (z (* %s 10) f08x))))", value);
    Parser::run(aux, "(w 2 (m (p 2 (z (* 150000 10) f08x)) (p 3 (z (* 150000 10) f08x))))");

    delay(100);
    // Serial.println(aux);

    // sprintf(aux, "(w 3 (m (p 0 (z (* %s 10) f08x)) (p 1 (z (* %s 10) f08x))))", value);
    Parser::run(aux, "(w 3 (m (p 0 (z (* 150000 10) f08x)) (p 1 (z (* 150000 10) f08x))))");

    // Serial.println(aux);

}

Result::Result(LiquidCrystal_I2C *lcd, E *e, char *script)
{
    this->lcd = lcd;
    this->script = script;
    this->cursor = new int(0);
    this->type = ResultType::Show;
}

Result::~Result() {}

void Result::setup()
{
    Parser::run(value, "(z (/ (n (m (r 3) (r 2) (r 1) (r 0))) 10) %06ld)");
    Parser::run(aux, "(z (/ (n (m (r 3) (r 2) (r 1) (r 0))) 10) %06ld)");
    Serial.println(value);
    Serial.println(aux);
    if(strcmp(value, aux) != 0)
    {
        type = ResultType::Error;
    }

    render();
}

void Result::action(LinkedList<View *> *views)
{
    Controls c = Controls::getInstance();

    if (type == ResultType::Edit)
    {
        if (c.up->update() && c.up->rose())
        {
            value[*cursor]++;
            render();
        }

        if (c.down->update() && c.down->rose())
        {
            value[*cursor]--;
            render();
        }

        if (c.right->update() && c.right->rose())
        {
            lcd->setCursor(*cursor + 1, 3);
            lcd->print(" ");
            *cursor += 1;
            *cursor %= 4;
            render();
        }

        if (c.left->update() && c.left->rose())
        {
            lcd->setCursor(*cursor + 1, 3);
            lcd->print(" ");

            *cursor -= 1;

            if (*cursor < 0)
            {
                *cursor = 0;
            }

            render();
        }
    }

    if (c.enter->update() && c.enter->rose())
    {
        if (type == ResultType::Show)
        {
            type = ResultType::Edit;
            render();
        }
        else if (type == ResultType::Edit)
        {
            lcd->clear();
            type = ResultType::Show;
            Serial.println(value);

            update();

            setup();
        }
    }

    if (c.back->update() && c.back->rose())
    {
        if (type == ResultType::Show)
        {
            lcd->clear();
            views->pop();
        }
        else if (ResultType::Edit)
        {
            lcd->clear();
            type = ResultType::Show;
            render();
        }
    }
}

void Result::render()
{
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);
    lcd->createChar(2, Symbols::arrow_up);

    lcd->setCursor(1, 1);
    if(type == ResultType::Edit || type == ResultType::Show)
    {
        lcd->print("Km:");
    }
    else
    {
        lcd->print("Erro!");
    }

    lcd->setCursor(1, 2);

    if(type == ResultType::Edit || type == ResultType::Show)
    {
        lcd->print(value);
    }
    else
    {
        lcd->print("Leia novamente");
    }

    lcd->setCursor(19, 3);
    lcd->write(1);

    if (type == ResultType::Edit)
    {
        lcd->setCursor(*cursor + 1, 3);
        lcd->write(2);
    }
}