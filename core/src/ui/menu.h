#ifndef MENU_H
#define MENU_H

#include <LiquidCrystal_I2C.h>

#include "math.h"
#include "view.h"
#include "symbols.h"
#include "controls.h"
#include "arch/e.h"
#include "ui.h"

class MenuItem
{
    public:
        const char *title;
        View *child;
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
        void draw();
        void update();
};

#endif