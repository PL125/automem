#include "menu.h"

Menu::Menu(LiquidCrystal_I2C *lcd, List<MenuItem> *items) {
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
    bouncer_enter->interval(20);

    bouncer_back = new Bounce();
    bouncer_back->attach(BACK);
    bouncer_back->interval(20);

    this->lcd = lcd;
    this->cursor = new int(0);
    this->items = items;
}

Menu::~Menu() {}

void Menu::render() const {
    lcd->createChar(0, Symbols::arrow);
    lcd->setCursor(0, *cursor);
    lcd->write(0);

    for (int i = 0; i < 4; i++)
    {
        lcd->setCursor(1, i);
        lcd->print(items->get(i).title);
    }
}

void Menu::action(Stack<View> *views) const {
    if (bouncer_up->update() && bouncer_up->rose())
    {
        lcd->setCursor(0, *cursor);
        lcd->print(" ");
        *cursor = (*cursor + 1) % items->length();
    }

    if (bouncer_down->update() && bouncer_down->rose())
    {
        lcd->setCursor(0, *cursor);
        lcd->print(" ");
        *cursor = (*cursor - 1) % items->length();
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
