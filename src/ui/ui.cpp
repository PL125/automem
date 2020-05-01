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


    menus = CircularList<Menu>();
    menus.add(&Menu("Imobilizador"));
    menus.add(&Menu("Airbag"));
    menus.add(&Menu("Odometro"));

    
    // menus = Stack<CircularList<Menu>>();
    // menus.push(circular_list);
    
};

void Ui::render(LiquidCrystal_I2C *lcd)
{
    lcd->setCursor(0, cursor);
    lcd->print(">");

    for (int i = 0; i < 4; i++)
    {
        lcd->setCursor(1, i);
        lcd->print(menus.head->value->title);
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