#include "menu.h"

Menu::Menu(LiquidCrystal_I2C *lcd, List<MenuItem> *items)
{
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);
    pinMode(ENTER, INPUT);
    pinMode(BACK, INPUT);

    bouncer_up = new Bounce();
    bouncer_up->attach(UP);
    bouncer_up->interval(20);

    bouncer_down = new Bounce();
    bouncer_down->attach(DOWN);
    bouncer_down->interval(20);

    bouncer_enter = new Bounce();
    bouncer_enter->attach(ENTER);
    bouncer_enter->interval(50);

    bouncer_back = new Bounce();
    bouncer_back->attach(BACK);
    bouncer_back->interval(50);

    this->lcd = lcd;
    this->items = items;
    this->top = new int(0);
    this->cursor = new int(0);
}

Menu::~Menu() {}

void Menu::render() const
{

    lcd->createChar(0, Symbols::arrow_right);
    lcd->setCursor(0, *cursor - *top);
    lcd->write(0);

    if(*top > 0)
    {
        lcd->createChar(1, Symbols::arrow_up);
        lcd->setCursor(19, 0);
        lcd->write(1);
    }

    if(*top < items->length() - 4)
    {
        lcd->createChar(2, Symbols::arrow_down);
        lcd->setCursor(19, 3);
        lcd->write(2);
    }

    for (int i = 0; i < min(items->length(), 4); i++)
    {
        lcd->setCursor(1, i);
        lcd->print(items->get(i + *top).title);
    }
}

void Menu::action(Stack<View> *views) const
{
    if (bouncer_up->update() && bouncer_up->rose())
    {
        lcd->setCursor(0, *cursor - *top);
        lcd->print(" ");

        *cursor += 1;
        *cursor %= items->length();
        
        if (*cursor >= *top + 4)
        {
            *top += 1;
            lcd->clear();
        }
        
        
        if(*cursor == 0) 
        {
            *top = 0;
            lcd->clear();
        }

        
    }

    if (bouncer_down->update() && bouncer_down->rose())
    {
        lcd->setCursor(0, (*cursor - *top) % 4);
        lcd->print(" ");

        *cursor -= 1;

        if (*cursor < *top)
        {
            if(*cursor < 0)
            {
                *top = items->length() - 4;
                *cursor = items->length() - 1;
            } 
            else
            {
                *top -= 1;
            }

            lcd->clear();
        }

        if(*cursor == items->length())
        {
            *top = items->length() - 4;
            lcd->clear();
        }

        
    }

    if (bouncer_enter->update() && bouncer_enter->rose())
    {
        MenuItem current_menu_item = items->get(*cursor);
        if (current_menu_item.view != nullptr)
        {
            lcd->clear();
            views->push(current_menu_item.view);
        }
    }

    if (bouncer_back->update() && bouncer_back->rose())
    {
        lcd->clear();
        views->pop();
    }
}
