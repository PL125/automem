#ifndef MENU_H
#define MENU_H

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#include "view.h"
#include "menu_item.h"
#include "../utils/list.h"

uint8_t arrow[8] = {0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00};


#define ENTER 6
#define BACK 5
#define UP 7
#define DOWN 8

class MenuItem;
class Menu : public View
{
    private:
        Bounce bouncer_up;
        Bounce bouncer_down;
        Bounce bouncer_enter;
        Bounce bouncer_back;
    public:
        int cursor;
        LiquidCrystal_I2C *lcd;
        List<MenuItem> *items;
        Menu(LiquidCrystal_I2C *lcd, List<MenuItem> *items);
        void render();
        void action(Stack<View> *views);
};

#endif