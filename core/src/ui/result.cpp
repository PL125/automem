#include "result.h"

char value[16];
char aux[16];

void update()
{
    char aux[128];
    // sprintf(aux, "(w 0 (m (p 6 (z (* %s 10) f08lx)) (p 7 (z (* %s 10) f08x))))", value);
    Parser::run(aux, "(w 0 (m (p 6 (z (* 50000 10) f08lx)) (p 7 (z (* 50000 10) f08lx))))");
    // Serial.println(aux);
    
    delay(100);

    // sprintf(aux, "(w 1 (m (p 4 (z (* %s 10) fl08x)) (p 5 (z (* %s 10) fl08x)))", value);
    
    Parser::run(aux, "(w 1 (m (p 4 (z (* 50000 10) f08lx)) (p 5 (z (* 50000 10) f08lx))))");

    delay(100);

    // Serial.println(aux);

    // sprintf(aux, "(w 2 (m (p 2 (z (* %s 10) f08lx)) (p 3 (z (* %s 10) f08lx)))", value);
    Parser::run(aux, "(w 2 (m (p 2 (z (* 50000 10) f08lx)) (p 3 (z (* 50000 10) f08lx))))");

    delay(100);
    // Serial.println(aux);

    // sprintf(aux, "(w 3 (m (p 0 (z (* %s 10) f08lx)) (p 1 (z (* %s 10) f08lx)))", value);
    Parser::run(aux, "(w 3 (m (p 0 (z (* 50000 10) f08lx)) (p 1 (z (* 50000 10) f08lx))))");

    // Serial.println(aux);

}

Result::Result(LiquidCrystal_I2C *lcd, char *script)
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

    draw();
}

void Result::update()
{

    Ui ui = Ui::getInstance();
    Controls c = Controls::getInstance();

    if (type == ResultType::Edit)
    {
        if (c.up->update() && c.up->rose())
        {
            value[*cursor]++;
            draw();
        }

        if (c.down->update() && c.down->rose())
        {
            value[*cursor]--;
            draw();
        }

        if (c.right->update() && c.right->rose())
        {
            lcd->setCursor(*cursor + 1, 3);
            lcd->print(" ");
            *cursor += 1;
            *cursor %= 4;

            draw();
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

            draw();
        }
    }

    if (c.enter->update() && c.enter->rose())
    {
        if (type == ResultType::Show)
        {
            type = ResultType::Edit;
            draw();
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
            ui.pop();
        }
        else if (ResultType::Edit)
        {
            lcd->clear();
            type = ResultType::Show;

            draw();
        }
    }
}

void Result::draw()
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