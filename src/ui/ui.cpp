#include "ui.h"


Ui::Ui() {
    this->menu = nullptr;
    this->cursor = 0;
}

Ui::Ui(Menu *menu)
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
    
    this->menu = menu;   
    this->cursor = 0;
};

void Ui::render(LiquidCrystal_I2C *lcd)
{
    lcd->setCursor(0, cursor);
    lcd->print(">");

    for (int i = 0; i < 4; i++)
    {
        lcd->setCursor(1, i);
        lcd->print(this->menu->items->get(i).title);
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

    if(bouncer_enter.update() && bouncer_enter.rose()) {
        lcd->clear();

        MenuItem current_menu_item = this->menu->items->get(cursor);
        
        if(current_menu_item.menu != nullptr)    
            this->menu = current_menu_item.menu;
    }
}