#include "ui.h"

const char mImmo[] PROGMEM = "Imobilizador";
const char mAirbag[] PROGMEM = "Airbag";
const char mOdometer[] PROGMEM = "Airbag";
const char mRadio[] PROGMEM = "Radio";
const char mSettings[] PROGMEM = "Configuracoes";

const char mVolkswagen[] PROGMEM = "Volkswagen";
const char mFiat[] PROGMEM = "Fiat";

const char mGolG493c66[] PROGMEM = "Gol G4 (93c66)";
const char mGolG493c66Read[] PROGMEM = "(z (/ (n (m (r 3) (r 2) (r 1) (r 0))) 10) f06ld)";

const char mFiatCd5404[] PROGMEM = "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))";


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
                    .title = mImmo
                }
            );

            items->add(
                MenuItem {
                    .title = mAirbag
                }
            );

            items->add(
                MenuItem {
                    .title = mOdometer,
                    .child = getView(3)
                }
            );

            items->add(
                MenuItem {
                    .title = mRadio,
                    .child = getView(4)
                }
            );

            items->add(
                MenuItem {
                    .title = mSettings
                }
            );
            
            return items;
        
        case 3: // Odometro

            items->add(
                MenuItem {
                    .title = mVolkswagen,
                    .child = getView(301)
                }
            );

            return items;

        case 301:
            
            items->add(
                MenuItem {
                    .title = mGolG493c66,
                    .child = getView(30100)
                }
            );

            return items;

        case 4: // Radio
        
            items->add(
                MenuItem {
                    .title = mFiat
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
    // switch(id)
    // {
    //     case 0:
    //         return mGolG493c66Read;
    //     case 1:
    //         return mFiatCd5404;
    // }
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
