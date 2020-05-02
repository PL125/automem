#include "menu.h"

Menu::Menu(LiquidCrystal_I2C *lcd, List<MenuItem> *items) {
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);
    pinMode(ENTER, INPUT);
    pinMode(BACK, INPUT);

    bouncer_up = Bounce();
    bouncer_up.attach(UP);
    bouncer_up.interval(20);

    bouncer_down = Bounce();
    bouncer_down.attach(DOWN);
    bouncer_down.interval(20);

    bouncer_enter = Bounce();
    bouncer_enter.attach(ENTER);
    bouncer_enter.interval(20);

    bouncer_back = Bounce();
    bouncer_back.attach(BACK);
    bouncer_back.interval(20);

    this->lcd = lcd;
    this->cursor = 0;
    this->items = items;
}

void Menu::render() {
    lcd->createChar(0, arrow);
    lcd->setCursor(0, cursor);
    lcd->write(0);

    for (int i = 0; i < 4; i++)
    {
        lcd->setCursor(1, i);
        lcd->print(items->get(i).title);
    }
}

void Menu::action(Stack<View> *views) {
    if (bouncer_up.update() && bouncer_up.rose())
    {
        lcd->setCursor(0, cursor);
        lcd->print(" ");
        cursor = (cursor + 1) % items->length();
    }

    if (bouncer_down.update() && bouncer_down.rose())
    {
        lcd->setCursor(0, cursor);
        lcd->print(" ");
        cursor = (cursor - 1) % items->length();
    }

    if (bouncer_enter.update() && bouncer_enter.rose())
    {
        MenuItem current_menu_item = items->get(cursor);
        if (current_menu_item.menu != nullptr)
        {
            lcd->clear();

            views->push(current_menu_item.menu);
        }
    }

    if (bouncer_back.update() && bouncer_back.rose())
    {
        lcd->clear();
        views->pop();
    }
}
