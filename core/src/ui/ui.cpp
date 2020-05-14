#include "ui.h"

#include "ui/strings.h"

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


View* Ui::getView(int id)
{
    LinkedList<MenuItem> *items;

    switch(id)
    {
        case 0:
            items = new LinkedList<MenuItem>();
            items->add(
                MenuItem {
                    .title = "Imobilizador"
                }
            );
            
            return new Menu(lcd, items);
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