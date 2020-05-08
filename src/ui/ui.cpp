#include "ui.h"


List<MenuItem>* radio_fiat(LiquidCrystal_I2C *lcd) {
    List<MenuItem> *items = new List<MenuItem>();

    items->add(MenuItem{
        .title = "CD5404 (24c32)",
        .view = new Result(
            lcd,
            &E24c32,
            "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))"
        )
    });

    return items;
}

List<MenuItem>* radio(LiquidCrystal_I2C *lcd) {
    List<MenuItem> *items = new List<MenuItem>();

    items->add(MenuItem{
        .title = "Fiat",
        .view = new Menu(
            lcd,
            radio_fiat(lcd)
        )
    });

    items->add(MenuItem{
        .title = "Volkswagen",
    });

    return items;
}

List<MenuItem>* main_menu(LiquidCrystal_I2C *lcd) {
    List<MenuItem> *items = new List<MenuItem>();

    items->add(MenuItem{
        .title = "Imobilizador",
    });

    items->add(MenuItem{
        .title = "Airbag",
    });

    items->add(MenuItem{
        .title = "Odometro",
    });

    items->add(MenuItem{
        .title = "Radio",
        .view = new Menu(
            lcd,
            radio(lcd)
        )
    });

    items->add(MenuItem{
        .title = "Configuracoes",
    });

    items->add(MenuItem{
        .title = "Teste 1",
    });

    items->add(MenuItem{
        .title = "Teste 2",
    });

    items->add(MenuItem{
        .title = "Teste 3",
    });

    return items;
}

Ui::Ui()
{
    this->lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->init();
    this->lcd->backlight();

    this->views = new Stack<View>();
    this->views->push(new Menu(lcd, main_menu(lcd)));
    
};

void Ui::render()
{
    views->top()->render();
    views->top()->action(views);
}