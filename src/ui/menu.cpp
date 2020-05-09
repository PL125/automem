#include "menu.h"

Menu::Menu(LiquidCrystal_I2C *lcd, LinkedList<MenuItem> *items)
{
    this->lcd = lcd;
    this->items = items;
    this->top = new int(0);
    this->cursor = new int(0);
}

Menu::~Menu() {}

void Menu::setup() const
{
}

void Menu::render() const
{

    lcd->createChar(0, Symbols::arrow_right);
    lcd->setCursor(0, *cursor - *top);
    lcd->write(0);

    if (*top > 0)
    {
        lcd->createChar(1, Symbols::arrow_up);
        lcd->setCursor(19, 0);
        lcd->write(1);
    }

    if (*top < items->size() - 4)
    {
        lcd->createChar(2, Symbols::arrow_down);
        lcd->setCursor(19, 3);
        lcd->write(2);
    }

    for (int i = 0; i < min(items->size(), 4); i++)
    {
        lcd->setCursor(1, i);
        lcd->print(items->get(i + *top).title);
    }
}

void Menu::action(LinkedList<View *> *views) const
{
    Controls c = Controls::getInstance();

    if (c.up->update() && c.up->rose())
    {
        lcd->setCursor(0, *cursor - *top);
        lcd->print(" ");

        *cursor += 1;
        *cursor %= items->size();

        if (*cursor >= *top + 4)
        {
            *top += 1;
            lcd->clear();
        }

        if (*cursor == 0)
        {
            *top = 0;
            lcd->clear();
        }
    }

    if (c.down->update() && c.down->rose())
    {
        lcd->setCursor(0, (*cursor - *top) % 4);
        lcd->print(" ");

        *cursor -= 1;

        if (*cursor < *top)
        {
            if (*cursor < 0)
            {
                *top = items->size() - 4;
                *cursor = items->size() - 1;
            }
            else
            {
                *top -= 1;
            }

            lcd->clear();
        }

        if (*cursor == items->size())
        {
            *top = items->size() - 4;
            lcd->clear();
        }
    }

    if (c.enter->update() && c.enter->rose())
    {
        MenuItem current_menu_item = items->get(*cursor);
        if (&current_menu_item.view != nullptr)
        {
            lcd->clear();
            views->add(current_menu_item.view);
            views->get(views->size() - 1)->setup();
        }
    }

    if (c.back->update() && c.back->rose())
    {
        lcd->clear();
        views->pop();
    }
}
