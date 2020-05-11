#include "ui.h"
#include "arch/e93c.h"

LinkedList<MenuItem> *radio_fiat(LiquidCrystal_I2C *lcd)
{
    LinkedList<MenuItem> *items = new LinkedList<MenuItem>();

    // Result* view = new Result(
    //     lcd,
    //     &E24c32,
    //     "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))");

    items->add(MenuItem{
        .title = "Teste 1",
    });

    items->add(MenuItem{
        .title = "Teste 2",
    });

    
    items->add(MenuItem{
        .title = "Teste 3",
    });

    items->add(MenuItem{
        .title = "Teste 4",
    });

    
    items->add(MenuItem{
        .title = "Teste 5",
    });

    items->add(MenuItem{
        .title = "Teste 6",
    });

    return items;
}

Ui::Ui()
{
    this->lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->begin();
    this->lcd->backlight();

    this->views = new LinkedList<View*>();

    // E24c E24c32 = E24c(4096, 0x50);

    E93c e = E93c(512, 9, 8);

    Menu* m = new Menu(lcd, radio_fiat(lcd));
    // Result* m = new Result(
    //     lcd,
    //     &e,
    //     "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))");

    m->setup();

    this->views->add(m);
};

void Ui::render()
{
    views->get(views->size() - 1)->render();
    views->get(views->size() - 1)->action(views);
}