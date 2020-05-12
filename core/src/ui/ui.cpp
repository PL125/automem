#include "ui.h"
#include "arch/e93c.h"

Ui::Ui()
{
    this->lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->begin();
    this->lcd->backlight();

    this->views = new LinkedList<View*>();

    E24c E24c32 = E24c(4096, 0x50);

    Result* m = new Result(
        lcd,
        &E24c32,
        "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))");

    m->setup();

    this->views->add(m);
};

void Ui::render()
{
    views->get(views->size() - 1)->action(views);
}