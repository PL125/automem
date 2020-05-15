#include "ui.h"

#include "ui/strings.h"

Ui::Ui()
{
    views = new LinkedList<View*>();
    lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    lcd->begin();
    lcd->backlight();

    push(3);
};

View* Ui::top()
{
    return views->get(views->size() - 1);
}

void Ui::pop()
{
    views->pop();

    top()->setup();
}

void Ui::push(int id)
{
    Serial.println(id);

    View *view = getView(id);
    views->add(view);
    
    view->setup();
}

View* Ui::getView(int id)
{
    LinkedList<MenuItem> *items = new LinkedList<MenuItem>();

    switch(id)
    {
        case 0:
            items->add(
                MenuItem {
                    .title = getString(m0),
                }
            );

            items->add(
                MenuItem {
                    .title = getString(m1),
                }
            );

            items->add(
                MenuItem {
                    .title = getString(m2),
                }
            );

            items->add(
                MenuItem {
                    .title = getString(m3),
                    .child = 2
                }
            );

            items->add(
                MenuItem {
                    .title = getString(m4),
                }
            );
            
            return new Menu(lcd, items);
        
        case 1:

            // char buf[30];
            // strcpy_P(buf, (char *)pgm_read_word(&m1));

            items->add(
                MenuItem {
                    .title = "NNNNN",
                }
            );

            items->add(
                MenuItem {
                    .title = "NNNNN",
                }
            );

            return new Menu(lcd, items);
        
        case 2:

            return new Result(lcd, getString(m8));
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