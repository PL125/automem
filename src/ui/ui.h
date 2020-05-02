#ifndef UI_H
#define UI_H 

#include <Bounce2.h>
#include <LiquidCrystal_I2C.h>

#include "menu.h"
#include "../utils/stack.h"

class Ui
{
    public:
        Stack<View> *views;
        int cursor;
        Ui(Menu *main_menu);
        void render(LiquidCrystal_I2C *lcd);
        void up();
        void down();
        void enter();
        void back();
};

#endif