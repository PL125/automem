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
        char *title;
        int child;
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

        void setup() const;   
        void draw() const;
        void update() const;
};

#endif