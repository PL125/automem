#include "ui.h"

Ui::Ui() {
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);
    pinMode(ENTER, INPUT);
    pinMode(BACK, INPUT);

    bouncer_up = Bounce();
    bouncer_up.attach(UP);
    bouncer_up.interval(20);

    bouncer_down = Bounce();
    bouncer_down.attach(DOWN);
    bouncer_down.interval(20);

    bouncer_enter = Bounce();
    bouncer_enter.attach(ENTER);
    bouncer_enter.interval(20);

    bouncer_back = Bounce();
    bouncer_back.attach(BACK);
    bouncer_back.interval(20);

    Menu m[] = {
        Menu("Imobilizador", nullptr),
        Menu("Airbag", nullptr),
        Menu("Odometro", nullptr),
        Menu("Configurações", nullptr)
    };

    menus = Stack<Menu[]>();
    menus.push(m);
};

void Ui::render(LiquidCrystal_I2C *lcd) {
    lcd->setCursor(0, cursor);
    lcd->print(">");

    for(int i=0; i<4; i++) {
        lcd->setCursor(1, i);
        lcd->print(menus.top()[i].title);
    }
}