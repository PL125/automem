#include "ui.h"
#include "arch/e93c.h"

Ui::Ui()
{
    lcd = LiquidCrystal_I2C(0x27, 20, 4);
    lcd.begin();
    lcd.backlight();

    views = LinkedList<View>();
    views.add(getView(0));
};

void Ui::render()
{
    views.get(views.size() - 1).action(views);
}


View Ui::getView(int id)
{
    switch(id)
    {
        case 0:
            Result(
                &lcd,
                getCmd(1)
            );
        case 1:
            Result(
                &lcd,
                getCmd(1)
            );
            break;
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