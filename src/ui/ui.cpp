#include "ui.h"

Ui::Ui()
{
    this->lcd = new LiquidCrystal_I2C(0x27, 20, 4);
    this->lcd->init();
    this->lcd->backlight();

    this->views = new Stack<View>();
    
    MenuItem item = MenuItem{
        .title = "Radio", 
        .view = new Result(
            lcd, 
            new Query{
                .e = &E24c32, 
                .script = "(merge (last (read 24)) (first (read 25)) (last (read 26)) (first (read 27)))"
            })
        };

    MenuItem item2 = MenuItem{
        .title = "Test"
    };

    // List<MenuItem> itemsRR = List<MenuItem>();
    // itemsRR.add(MenuItem("CD5404 (24c32)", new Result(lcd, result)));

    // List<MenuItem> itemsR = List<MenuItem>();
    // itemsR.add(MenuItem("Fiat", new Menu(lcd, &itemsRR)));

    List<MenuItem> *items = new List<MenuItem>();
    items->add(item2);

    Menu *initial = new Menu(lcd, items);

    this->views->push(initial);
    this->cursor = 0;
};

void Ui::render()
{
    views->top()->render();
    views->top()->action(views);
}