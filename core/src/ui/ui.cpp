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
        case 0: // Main Menu
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
                    .title = "Odometro",
                    .child = getView(3)
                }
            );

            items->add(
                MenuItem {
                    .title = "Radio",
                    .child = getView(4)
                }
            );

            items->add(
                MenuItem {
                    .title = "Configuracoes"
                }
            );
            
            return items;
        
        case 3: // Odometro

            items->add(
                MenuItem {
                    .title = "Volkswagen",
                    .child = getView(301)
                }
            );

            return items;

        case 301:
            
            items->add(
                MenuItem {
                    .title = "Gol G4 (93c66)",
                    .child = getView(30100)
                }
            );

            return items;

        case 4: // Radio
        
            items->add(
                MenuItem {
                    .title = "Fiat"
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
        case 3: // Odometro
            return new Menu(lcd, getItems(3)); 

        case 301:
            return new Menu(lcd, getItems(301));

        case 30100:
            return new Result(lcd, getRead(1), nullptr);

        case 4: // Radio
            return new Menu(lcd, getItems(4));
        // case 2:
        //     return new Result(lcd, getRead(1));
        
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

char* Ui::getRead(int id)
{
    switch(id)
    {
        case 0:
            return "(z (/ (n (m (r 3) (r 2) (r 1) (r 0))) 10) f06ld)";
        case 1:
            return "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))";
    }
}

void Ui::callWrite(int id, long value)
{

    LinkedList<char*> *items = new LinkedList<char*>();

    switch(id)
    {
        case 0:
            char buffer[64];

            

    }
};

Ui& Ui::getInstance()
{
    static Ui instance;

    return instance;
}


void Ui::update()
{
    top()->update();
}
