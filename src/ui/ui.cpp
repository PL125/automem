#include "ui.h"



Ui::Ui(Menu *main_menu)
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
    
    this->menus = new Stack<Menu>();   
    this->menus->push(main_menu);
    this->cursor = 0;
};

void Ui::render(LiquidCrystal_I2C *lcd)
{
    lcd->setCursor(0, cursor);
    lcd->print(">");

    for (int i = 0; i < 4; i++)
    {
        lcd->setCursor(1, i);
        lcd->print(this->menus->top().items->get(i).title);
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
        MenuItem current_menu_item = this->menus->top().items->get(cursor);
        if(current_menu_item.menu != nullptr) {    
            lcd->clear();

            this->menus->push(current_menu_item.menu);
        }
    }

    if(bouncer_back.update() && bouncer_back.rose()) {
        lcd->clear();
        this->menus->pop();
    }
}