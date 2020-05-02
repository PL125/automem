#include "ui.h"

Ui::Ui()
{
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

    cursor = 0;

    
    MenuItem item = MenuItem("BBBB");

    List<MenuItem> items;
    items.add(&item);
    items.add(&item);
    items.add(&item);
    items.add(&item);
    // items.insert(&item);
    // items.insert(&item);
    // items.insert(&item);

    Menu m = Menu(&items);
    menu = &m;   
};

void Ui::render(LiquidCrystal_I2C *lcd)
{
    lcd->setCursor(0, cursor);
    lcd->print(">");

    for (int i = 0; i < 4; i++)
    {
        lcd->setCursor(1, i);
        lcd->print(menu->items->get(i).title);
    }

    if (bouncer_up.update() && bouncer_up.rose())
    {
        lcd->setCursor(0, cursor);
        lcd->print(" ");
        cursor = (cursor + 1) % 7;
    }

    if (bouncer_down.update() && bouncer_down.rose())
    {
        lcd->setCursor(0, cursor);
        lcd->print(" ");
        cursor = (cursor - 1) % 7;
    }

    //    if(bouncer_enter.update() && bouncer_enter.rose()) {
    //      lcd->clear();
    //      cursor = 0;
    //      current_menu = main_menu->submenus;
    //    }
}