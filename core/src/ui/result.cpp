#include "result.h"

char aux[16];
char value[16];

Result::Result(LiquidCrystal_I2C *lcd, char* pMem, char *read)
{
    this->lcd = lcd;

    this->pMem = pMem;
    this->read = read;
    // this->write = write;

    this->cursor = new int(0);
    this->type = ResultType::Show;
}

Result::~Result() {}

void Result::setup() const
{
    // value = new char(16);

    Serial.println(read);    
    Serial.println(pMem);    
    Parser::call(value, pMem);
    Parser::call(value, read);
    Parser::call(aux, read);

    if(strcmp(value, aux) != 0)
    {
        type = ResultType::Error;
    }

    draw();
}

void Result::update() const
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
            lcd->print(F(" "));
            *cursor += 1;
            *cursor %= 4;

            draw();
        }

        if (c.left->update() && c.left->rose())
        {
            lcd->setCursor(*cursor + 1, 3);
            lcd->print(F(" "));

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

void Result::draw() const
{
    lcd->createChar(0, Symbols::square);
    lcd->createChar(1, Symbols::enter);
    lcd->createChar(2, Symbols::arrow_up);

    lcd->setCursor(1, 1);
    if(type == ResultType::Edit || type == ResultType::Show)
    {
        lcd->print(F("Km:"));
    }
    else
    {
        lcd->print(F("Erro!"));
    }

    lcd->setCursor(1, 2);

    if(type == ResultType::Edit || type == ResultType::Show)
    {
        lcd->print(value);
    }
    else
    {
        lcd->print(F("Leia novamente"));
    }

    lcd->setCursor(19, 3);
    lcd->write(1);

    if (type == ResultType::Edit)
    {
        lcd->setCursor(*cursor + 1, 3);
        lcd->write(2);
    }
}