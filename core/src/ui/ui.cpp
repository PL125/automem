#include "ui.h"

Ui::Ui()
{
    lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    lcd->begin();
    lcd->backlight();

    views = new LinkedList<View*>();
    views->add(getView(0));
    top()->setup();
};

View* Ui::top()
{
    return views->get(views->size() - 1);
}

View* Ui::pop()
{
    return views->pop();
}

void Ui::push(View* view)
{
    views->add(view);
    top()->setup();
}

LinkedList<MenuItem>* Ui::getItems(int id)
{
    LinkedList<MenuItem> *items = new LinkedList<MenuItem>();

    switch(id)
    {
        case 0:
            items->add(
                MenuItem {
                    .title = "Imobilizador"
                }
            );

            items->add(
                MenuItem {
                    .title = "Airbag"
                }
            );

            items->add(
                MenuItem {
                    .title = "Odometro"
                }
            );

            items->add(
                MenuItem {
                    .title = "Radio"
                }
            );

            items->add(
                MenuItem {
                    .title = "Configuracoes"
                }
            );
            
            return items;
    }
}

View* Ui::getView(int id)
{
    switch(id)
    {
        case 0:
            return new Menu(lcd, getItems(0));
        case 1:
            return new Result(lcd, getCmd(0));
        case 2:
            return new Result(lcd, getCmd(1));
    }
}

E Ui::getE(int id)
{
    switch(id)
    {
        case 1:
            return E93c(512, 9, 8);

    }
}

char* Ui::getCmd(int id)
{
    switch(id)
    {
        case 0:
            return "(z (/ (n (m (r 3) (r 2) (r 1) (r 0))) 10) f06ld)";
        case 1:
            return "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))";
    }
}

Ui& Ui::getInstance()
{
    static Ui instance;

    return instance;
}


void Ui::update()
{
    top()->update();
}
