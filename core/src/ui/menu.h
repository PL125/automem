#ifndef MENU_H
#define MENU_H

#include <LiquidCrystal_I2C.h>

#include "math.h"
#include "view.h"
#include "symbols.h"
#include "controls.h"
#include "arch/e.h"

class MenuItem
{
    public:
        char *title;
        View *view;
};

class Menu : public View
{
    public:
        int *top;
        int *cursor;

        LiquidCrystal_I2C *lcd;
        LinkedList<MenuItem> *items;

        Menu(LiquidCrystal_I2C *lcd, LinkedList<MenuItem> *items);
        ~Menu();

        void setup();   
        void render();
        void action(LinkedList<View*> *views);
};

#endif