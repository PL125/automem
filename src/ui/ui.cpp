#include "ui.h"

#include "menu.h"

Ui::Ui()
{

    struct MenuItem
    {
        char *title;
        List<Menu> *submenus;
        MenuItem(char *title, List<Menu> *submenus)
        {
            this->title = title;
            this->submenus = submenus;
        }
    };

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

    List<MenuItem> items = List<MenuItem>();
    items.add(&MenuItem("Teste", nullptr));
    items.add(&MenuItem("Teste 2", nullptr));
    items.add(&MenuItem("Teste 3", nullptr));

    menu = Menu(items);
    // menus = Menu(

    // )
    // menus.add(&Menu("Imobilizador"));
    // menus.add(&Menu("Airbag"));
    // menus.add(&Menu("Odometro"));

    
    // menus = Stack<CircularList<Menu>>();
    // menus.push(circular_list);
    
};

void Ui::render(LiquidCrystal_I2C *lcd)
{
    lcd->setCursor(0, cursor);
    lcd->print(">");

    for (int i = 0; i < 3; i++)
    {
        
        lcd->setCursor(1, i);
        lcd->print(menus->title);
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