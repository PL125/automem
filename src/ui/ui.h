#ifndef UI_H
#define UI_H 

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#include "menu.h"
#include "../utils/stack.h"

#define ENTER 6
#define BACK 5
#define UP 7
#define DOWN 8

class Ui
{  
    private:
        Stack <Menu[]> menus;
        Bounce bouncer_up;
        Bounce bouncer_down;
        Bounce bouncer_enter;
        Bounce bouncer_back;
    public:
        int cursor;
        Ui();
        void render(LiquidCrystal_I2C *lcd);
        void up();
        void down();
        void enter();
        void back();
};

#endif