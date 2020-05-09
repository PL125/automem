#include "ui.h"

LinkedList<MenuItem> *radio_fiat(LiquidCrystal_I2C *lcd)
{
    LinkedList<MenuItem> *items = new LinkedList<MenuItem>();

    Result* view = new Result(
        lcd,
        &E24c32,
        "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))");

    items->add(MenuItem{
        .title = "CD5404 (24c32)",
        .view = view});

    return items;
}

Ui::Ui()
{
    this->lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->init();
    this->lcd->backlight();

    this->views = new LinkedList<View*>();

    Menu* m = new Menu(lcd, radio_fiat(lcd));

    this->views->add(m);
};

void Ui::render()
{
    views->get(views->size() - 1)->render();
    views->get(views->size() - 1)->action(views);
}