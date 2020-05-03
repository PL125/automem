#ifndef MENU_H
#define MENU_H

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#include "view.h"
#include "menu_item.h"
#include "../utils/list.h"

#define ENTER 6
#define BACK 5
#define UP 7
#define DOWN 8

class MenuItem;
class Menu : public View
{
    private:
        Bounce *bouncer_up;
        Bounce *bouncer_down;
        Bounce *bouncer_enter;
        Bounce *bouncer_back;
    public:
        
        int *cursor;
        LiquidCrystal_I2C *lcd;
        List<MenuItem> *items;
        Menu(LiquidCrystal_I2C *lcd, List<MenuItem> *items);
        ~Menu();
        void render() const;
        void action(Stack<View> *views) const;
};

#endif